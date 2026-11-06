#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;

    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int M = *max_element(cnt.begin(), cnt.end());

    vector<ll> dp(n + 1, 0);
    dp[0] = 1;

    // 已经处理的数字，其原数量之和
    int sum = 0;

    for (int x = 1; x <= n; x++) {
        int c = cnt[x];
        if (c == 0) continue;

        vector<ll> ndp(n + 1, 0);

        for (int j = 0; j <= sum; j++) {
            // 目标中不包含 x
            ndp[j] = (ndp[j] + dp[j]) % MOD;

            // 目标中包含 x：
            // 可以出现 1 到 c 次，共 c 种选择
            ndp[j + c] = (ndp[j + c] + dp[j] * c) % MOD;
        }

        dp.swap(ndp);
        sum += c;
    }

    ll ans = 0;
    for (int j = M; j <= n; j++) {
        ans = (ans + dp[j]) % MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}