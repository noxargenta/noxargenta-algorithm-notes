#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    // 1. 计算前缀和并寻找最小值
    vector<int> P(n + 1, 0);
    int min_P = 0;
    for (int i = 0; i < n; ++i) {
        P[i + 1] = P[i] + (s[i] == '(' ? 1 : -1);
        min_P = min(min_P, P[i + 1]);
    }

    // 2. 找到达到前缀和最小值的任意断点 p*
    int p_star = -1;
    for (int i = 0; i <= n; ++i) {
        if (P[i] == min_P) {
            p_star = i;
            break; // 找第一个满足条件的断点即可
        }
    }

    // 3. 收集断点左侧所有的 '(' 和断点右侧所有的 ')'
    vector<int> allowed;
    for (int i = 0; i < p_star; ++i) {
        if (s[i] == '(') {
            allowed.push_back(i);
        }
    }
    for (int i = p_star; i < n; ++i) {
        if (s[i] == ')') {
            allowed.push_back(i);
        }
    }

    // 4. 贪心进行至多 k 次有效消除
    string ans(n, '0');
    int deletions = min(k, (int)allowed.size());
    for (int i = 0; i < deletions; ++i) {
        ans[allowed[i]] = '1';
    }

    cout << ans << "\n";
}

int main() {
    // 优化标准 I/O 操作以提升读取速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}