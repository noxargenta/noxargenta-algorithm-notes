#include <iostream>
#include <vector>
#include <map>

// 使用 long long 来防止整数溢出，因为药量总和可能非常大
using ll = long long;

int main() {
    // 加速输入输出
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    ll k;
    std::cin >> n >> k;

    // day_reduction_map[d] 表示在第 d 天，总药量会减少多少
    std::map<ll, ll> day_reduction_map;
    ll total_pills = 0;

    // 1. 读取输入，计算第1天的总药量，并收集所有“药量减少”事件
    for (int i = 0; i < n; ++i) {
        ll a, b;
        std::cin >> a >> b;
        total_pills += b;
        // 在第 a+1 天，总药量会减少 b
        day_reduction_map[a + 1] += b;
    }

    // 2. 检查第1天是否满足条件
    if (total_pills <= k) {
        std::cout << 1 << std::endl;
        return 0;
    }

    // 3. 按时间顺序（map的键已自动排序）处理事件
    for (auto const& [day, reduction] : day_reduction_map) {
        // 更新当前的总药量
        total_pills -= reduction;

        // 检查是否满足条件
        if (total_pills <= k) {
            // 这是第一次满足条件，所以这一天就是答案
            std::cout << day << std::endl;
            return 0; // 找到答案，程序结束
        }
    }

    return 0;
}