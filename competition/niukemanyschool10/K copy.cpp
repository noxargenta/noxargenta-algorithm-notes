#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 将宏定义的常量转换为 const 常量
const long long INFLL = 0x7f7f7f7f7f7f7f7fLL;

void solve() {
    int n;
    cin >> n;
    int N = 3 * n;
    
    // 使用明确的类型替代 vi 和 vvi 宏
    vector<long long> g(1LL << N);
    vector<long long> dp(1LL << N, -INFLL);
    vector<vector<long long>> a(N, vector<long long>(N, 1));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                // 1LL 确保位移操作不会溢出
                long long cur = (1LL << i) | (1LL << j) | (1LL << k);
                g[cur] = a[i][j] + a[i][k] + a[j][k];
            }
        }
    }

    vector<vector<long long>> b(n + 1);
    for (long long i = 0; i < (1LL << N); i++) {
        // 使用 __builtin_popcountll 处理 long long 类型的掩码
        int c = __builtin_popcountll(i);
        if (c % 3 == 0) {
            b[c / 3].push_back(i);
        }
    }

    dp[0] = 0;
    for (int cnt = 0; cnt < n; cnt++) {
        for (auto mask : b[cnt]) {
            if (dp[mask] == -INFLL) continue;

            vector<int> tmp;
            for (int j = 0; j < N; j++) {
                if (!((mask >> j) & 1)) {
                    tmp.push_back(j);
                }
            }
            int m = tmp.size();

            int i = 0;
            for (int j = i + 1; j < m; j++) {
                for (int k = j + 1; k < m; k++) {
                    long long cur = (1LL << tmp[i]) + (1LL << tmp[j]) + (1LL << tmp[k]);
                    dp[mask ^ cur] = max(dp[mask ^ cur], dp[mask] + g[cur]);
                }
            }
        }
    }
    cout << dp.back() << "\n";
}

int main() {
    // 优化输入输出
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}