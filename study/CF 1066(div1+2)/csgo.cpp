#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <sstream>

using namespace std;

// 文件名
const string DATA_FILE = "out.txt";
const string CONFIG_FILE = "config.txt";

// --- 数据结构 ---
struct TradeRecord {
    string timestamp_str;
    string name;
    double cost;
    string platform;
    double sell_price;
    double profit;
    double roi;
    time_t raw_time;
};

struct Platform {
    string name;
    double sell_price;
    double cash_in_hand;
    double profit;
    double roi;
};

// --- 时间工具 ---
string get_current_time_str() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", ltm);
    return string(buffer);
}

time_t parse_time_str(const string& time_str) {
    tm tm_struct = {};
    int year, month, day, hour, minute, second;
    if (sscanf(time_str.c_str(), "%d-%d-%d %d:%d:%d", 
        &year, &month, &day, &hour, &minute, &second) == 6) {
        tm_struct.tm_year = year - 1900;
        tm_struct.tm_mon = month - 1;
        tm_struct.tm_mday = day;
        tm_struct.tm_hour = hour;
        tm_struct.tm_min = minute;
        tm_struct.tm_sec = second;
        return mktime(&tm_struct);
    }
    return 0;
}

// --- 配置文件 (记忆屏蔽) ---
string load_last_ignore() {
    ifstream in(CONFIG_FILE);
    string line;
    if (in.is_open()) {
        getline(in, line);
        in.close();
    }
    return line;
}

void save_ignore_setting(const string& setting) {
    ofstream out(CONFIG_FILE);
    if (out.is_open()) {
        out << setting;
        out.close();
    }
}

// --- 核心：文件读写与对齐 ---

// 读取数据（兼容 Tab 分隔）
vector<TradeRecord> load_records() {
    vector<TradeRecord> records;
    ifstream infile(DATA_FILE);
    if (!infile.is_open()) return records;

    string line;
    // 跳过表头和分割线
    getline(infile, line); 
    getline(infile, line);

    while (getline(infile, line)) {
        if (line.size() < 5) continue; 

        // 使用 Tab 分割
        stringstream ss(line);
        string segment;
        vector<string> segs;
        
        while(getline(ss, segment, '\t')) {
            // 只有非空的片段才算有效数据（处理多个Tab的情况）
            if (!segment.empty()) {
                // 去除可能的首尾空格
                segment.erase(0, segment.find_first_not_of(" "));
                segment.erase(segment.find_last_not_of(" ") + 1);
                segs.push_back(segment);
            }
        }

        // 需要解析出至少7个字段
        if (segs.size() >= 7) {
            TradeRecord r;
            try {
                r.timestamp_str = segs[0];
                r.name = segs[1];
                r.cost = stod(segs[2]);
                r.platform = segs[3];
                r.sell_price = stod(segs[4]);
                r.profit = stod(segs[5]);
                string roi_str = segs[6];
                if (!roi_str.empty() && roi_str.back() == '%') roi_str.pop_back();
                r.roi = stod(roi_str);
                r.raw_time = parse_time_str(r.timestamp_str);
                records.push_back(r);
            } catch (...) { continue; }
        }
    }
    infile.close();
    return records;
}

// 写入数据（使用 Tab 智能对齐）
void save_records(vector<TradeRecord>& records) {
    ofstream outfile(DATA_FILE);
    if (!outfile.is_open()) return;

    // 表头：用 Tab 隔开
    outfile << "记录时间" << "\t\t"
            << "饰品名称" << "\t\t\t" // 名称后面多留几个 Tab
            << "成本" << "\t"
            << "平台" << "\t"
            << "售价" << "\t"
            << "净赚" << "\t"
            << "利润率" << endl;
    
    outfile << "------------------------------------------------------------------------------------------------" << endl;

    for (const auto& r : records) {
        // 1. 时间 (固定)
        outfile << r.timestamp_str << "\t";

        // 2. 名称 (智能 Tab)
        // 这是一个简单的视觉对齐策略：名字短补3个Tab，中等补2个，长补1个
        outfile << r.name;
        if (r.name.length() < 8) outfile << "\t\t\t";      // 名字很短，补3个
        else if (r.name.length() < 16) outfile << "\t\t"; // 名字中等，补2个
        else outfile << "\t";                             // 名字长，补1个

        // 3. 其他数据 (用 Tab 隔开)
        outfile << fixed << setprecision(2) << r.cost << "\t"
                << r.platform << "\t"
                << r.sell_price << "\t"
                << r.profit << "\t"
                << r.roi << "%" << endl;
    }
    outfile.close();
}

void update_file(const string& item_name, double cost, const Platform& best_p) {
    vector<TradeRecord> records = load_records();
    
    // 24小时清理
    time_t now = time(0);
    vector<TradeRecord> valid_records;
    for (const auto& r : records) {
        if (difftime(now, r.raw_time) < 24 * 3600) {
            valid_records.push_back(r);
        }
    }

    TradeRecord new_r;
    new_r.timestamp_str = get_current_time_str();
    new_r.raw_time = now;
    new_r.name = item_name;
    new_r.cost = cost;
    new_r.platform = best_p.name;
    new_r.sell_price = best_p.sell_price;
    new_r.profit = best_p.profit;
    new_r.roi = best_p.roi;
    valid_records.push_back(new_r);

    // 排序
    sort(valid_records.begin(), valid_records.end(), [](const TradeRecord& a, const TradeRecord& b) {
        return a.roi > b.roi;
    });

    save_records(valid_records);
    cout << "[成功] 已更新 out.txt (Tab 智能对齐)" << endl;
}

// --- 主程序 ---
int main() {
    cout << fixed << setprecision(2);
    double discount_rate;
    string ignore_input;
    bool skip_buff = false, skip_uu = false, skip_c5 = false;

    cout << "========================================================" << endl;
    cout << "      CS 搬砖计算器 v10.0 (Tab 完美对齐版)" << endl;
    cout << "========================================================" << endl;

    cout << "请输入余额折扣率 (例如 0.65): ";
    while (!(cin >> discount_rate)) {
        cout << "输入无效: "; cin.clear(); cin.ignore(10000, '\n');
    }
    cin.ignore(10000, '\n');

    // --- 记忆屏蔽逻辑 ---
    string last_setting = load_last_ignore();
    bool use_new_setting = true;

    if (!last_setting.empty()) {
        cout << "\n[记忆] 上次屏蔽: [ " << last_setting << " ]" << endl;
        cout << ">>> 是否继续? (回车=是, 输入 n=否): ";
        string choice;
        getline(cin, choice);

        if (choice.empty()) {
            ignore_input = last_setting;
            use_new_setting = false;
        }
    }

    if (use_new_setting) {
        cout << "\n[设置] 请输入要屏蔽的平台 (b=buff, u=uu, c=c5)" << endl;
        cout << ">>> 都不屏蔽请直接回车: ";
        getline(cin, ignore_input);
        save_ignore_setting(ignore_input);
    }

    for(auto &c : ignore_input) if(c >= 'A' && c <= 'Z') c += 32;
    if (ignore_input.find('b') != string::npos) skip_buff = true;
    if (ignore_input.find('u') != string::npos) skip_uu = true;
    if (ignore_input.find('c') != string::npos) skip_c5 = true;

    if (skip_buff || skip_uu || skip_c5) {
        cout << ">>> 已屏蔽: " << (skip_buff?"buff ":"") << (skip_uu?"uu ":"") << (skip_c5?"c5 ":"") << "<<<" << endl;
    }

    if (skip_buff && skip_uu && skip_c5) return 0;

    // --- 循环 ---
    while (true) {
        double steam_price = 0, p_buff = 0, p_uu = 0, p_c5 = 0;
        
        cout << "\n--------------------------------------------------------" << endl;
        cout << "请输入价格 (-1 退出):" << endl;
        cout << "格式: [Steam]";
        if (!skip_buff) cout << " [buff]";
        if (!skip_uu)   cout << " [uu]";
        if (!skip_c5)   cout << " [c5]";
        cout << endl << "> ";
        
        cin >> steam_price;
        if (steam_price == -1) break;

        bool fail = false;
        if (!skip_buff) { if(!(cin >> p_buff)) fail = true; }
        if (!skip_uu)   { if(!(cin >> p_uu))   fail = true; }
        if (!skip_c5)   { if(!(cin >> p_c5))   fail = true; }

        if (fail) {
            cout << "输入错误，请重试。" << endl;
            cin.clear(); cin.ignore(10000, '\n');
            continue;
        }

        double cost = steam_price * discount_rate;
        vector<Platform> platforms;
        
        if (!skip_buff) {
            double net = p_buff * 0.975 * 0.99; 
            platforms.push_back({"buff", p_buff, net, net - cost, (net - cost)/cost * 100.0});
        }
        if (!skip_uu) {
            double net = p_uu * 0.99 * 0.99;
            platforms.push_back({"uu", p_uu, net, net - cost, (net - cost)/cost * 100.0});
        }
        if (!skip_c5) {
            double net = p_c5 * 1.00 * 0.99;
            platforms.push_back({"c5", p_c5, net, net - cost, (net - cost)/cost * 100.0});
        }

        sort(platforms.begin(), platforms.end(), [](const Platform &a, const Platform &b) {
            return a.roi > b.roi;
        });

        cout << "成本: " << cost << " | ";
        if (platforms[0].roi > 10.0) {
            cout << ">>> 推荐! (利润 " << platforms[0].roi << "%) <<<" << endl;
            
            cout << "平台\t售价\t到手\t利润率" << endl;
            for (const auto &p : platforms) {
                cout << p.name << "\t" << p.sell_price << "\t" << p.cash_in_hand << "\t" << p.roi << "%" << endl;
            }

            string item_name;
            cout << "\n请输入饰品名称 (回车跳过): ";
            cin.ignore(10000, '\n');
            getline(cin, item_name);

            if (!item_name.empty()) {
                update_file(item_name, cost, platforms[0]);
            } else {
                cout << "已跳过。" << endl;
            }

        } else {
            cout << "最高: " << platforms[0].roi << "% (" << platforms[0].name << ") - 不推荐" << endl;
        }
    }
    return 0;
}