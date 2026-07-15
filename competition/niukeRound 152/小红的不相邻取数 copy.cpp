#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const ll INF = 2e18 + 9;

void solve() {
    int n;
    cin >> n;
    
    // 使用从 1 开始的下标，大小设为 n + 1
    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];

    // 定义 dp 数组：dp[i][0] 和 dp[i][1]
    // dp[n+1][2]，全部初始化为 0
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));

    // 初始化第 0 段的状态
    dp[0][0] = 0;
    dp[0][1] = -INF;

    for (int i = 1; i <= n; ++i) {
        ll x = a[i];
        ll k = b[i];

        if (x <= 0) {
            // 负数或 0 的段，统统不取
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]); 
            dp[i][1] = -INF; // 没取数，不可能以“取”结尾
        } else {
            // 正数的段，分类讨论
            // 1. 求 dp[i][0] (当前段最后一个数不取)
            ll from_0 = dp[i - 1][0] + (k / 2) * x;         // 前一段末尾没取，当前段最多取 k/2 个
            ll from_1 = dp[i - 1][1] + ((k - 1) / 2) * x;   // 前一段末尾取了，当前段最多取 (k-1)/2 个
            dp[i][0] = max(from_0, from_1);

            // 2. 求 dp[i][1] (当前段最后一个数 取)
            ll from_0_take = dp[i - 1][0] + ((k + 1) / 2) * x; // 前一段没取，当前段最多取 (k+1)/2 个
            ll from_1_take = dp[i - 1][1] + (k / 2) * x;       // 前一段取了，当前段最多取 k/2 个
            dp[i][1] = max(from_0_take, from_1_take);
        }
    }

    // 最后的答案就是处理完第 n 段后的最大值
    cout << max(dp[n][0], dp[n][1]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}