#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long

const ll INF=LLONG_MAX;
void solve() {
    int n, m;
    long long A, B, C;
    cin >> n >> m >> A >> B >> C;

    const long long hit = B - A;
    const long long miss = C - A;

    vector<vector<long long>> dp(m + 1, vector<long long>(m + 1, INF));
    vector<long long> best(m + 1, INF);
    dp[0][0] = best[0] = 0;
    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        for (int y = 0; y <= m; ++y) {
            if (y == x) continue;

            long long value = dp[x][y];
            long long hitBase = min(dp[x][y], dp[y][x]);

            if (hitBase != INF) value = min(value, hitBase + hit);
            if (best[y] != INF) value = min(value, best[y] + miss);

            dp[x][y] = value;
            best[x] = min(best[x], value);
        }
        ans = min(ans, best[x]);
    }

    cout << n * A + ans << '\n';
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}