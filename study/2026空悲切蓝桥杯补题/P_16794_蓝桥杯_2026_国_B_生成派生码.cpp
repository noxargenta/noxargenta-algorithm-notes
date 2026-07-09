#include <bits/stdc++.h>
using namespace std;

int main() {
    long long ans = 0;

    // 2 位到 8 位的所有正整数都可以生成
    long long part1 = 99999990;

    // 8 位基础码中，以 1 开头的部分
    long long part2 = 180000000;

    unordered_set<int> st;
    st.reserve(20000000);

    // 枚举以 2 开头且不超过 20260606 的基础码
    for (int x = 20000000; x <= 20260606; x++) {
        string s = to_string(x);

        // 枚举插入位置
        for (int pos = 0; pos <= (int)s.size(); pos++) {
            // 枚举插入的数字
            for (char c = '0'; c <= '9'; c++) {
                // 不能在最左边插入 0，否则会有前导零
                if (pos == 0 && c == '0') continue;

                string t = s;
                t.insert(t.begin() + pos, c);

                // 前两类已经统计过，不能重复计算
                if (t[0] == '1' || t[1] == '1') continue;

                st.insert(stoi(t));
            }
        }
    }

    long long part3 = st.size();

    ans = part1 + part2 + part3;

    cout << ans << endl;

    return 0;
}
