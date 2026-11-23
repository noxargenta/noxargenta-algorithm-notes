#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long

const ll INF = LLONG_MAX;

void solve() {
    int n, m;
    long long A, B, C;
    cin >> n >> m >> A >> B >> C;

    // 每次请求都先把 A 算进基准费用，因此直接访问的相对费用为 0。
    const long long hit = B - A;   // 缓存命中的相对费用
    const long long miss = C - A;  // 缓存未命中的相对费用

    // dp[u][v]：当前缓存中 u 最近使用、v 较早使用时的最小相对费用。
    // 相对费用 = 已花的实际费用 - 已处理的请求数 * A。
    // 0 表示空槽，INF 表示无法到达该状态。
    vector<vector<long long>> dp(m + 1, vector<long long>(m + 1, INF));

    // best[u]：第 u 行的最小值，即所有 dp[u][v] 中的最小值。
    vector<long long> best(m + 1, INF);
    dp[0][0] = best[0] = 0;  // 初始缓存为空，费用为 0。
    long long ans = 0;       // 当前所有缓存状态中的最小相对费用。

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        // 走缓存后，x 一定排在最前面，因此只需尝试更新第 x 行。
        // 其他行可以通过直接访问原样保留，因为相对费用增加 0。
        for (int y = 0; y <= m; ++y) {
            if (y == x) continue;  // 同一地址不能占两个槽。

            // 方式一：直接访问 x，原来的缓存 [x, y] 保持不动。
            long long value = dp[x][y];

            // 方式二：缓存命中。原来是 [x, y] 或 [y, x]，
            // 访问 x 后都会变成 [x, y]。
            long long hitBase = min(dp[x][y], dp[y][x]);
            if (hitBase != INF) value = min(value, hitBase + hit);

            // 方式三：缓存未命中。原来是 [y, z]，
            // 插入 x 后保留 y，得到 [x, y]。   
            // 如果 best[y] 恰好来自 [y, x]，实际会命中。
            // 上面已按命中费用算过它，且 hit <= miss，因此取 min 时无碍。
            if (best[y] != INF) value = min(value, best[y] + miss);

            // 只写第 x 行，读取的第 y 行仍是本次请求前的值。
            dp[x][y] = value;
            best[x] = min(best[x], value);
        }

        // 只有第 x 行可能出现更小的值。
        ans = min(ans, best[x]);
    }

    // 加回基准费用，得到实际的最小总时间。
    cout << n * A + ans << '\n';
}

signed main() {
    // freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;  // 原题第一行是测试组数，提交时取消注释。
    while (_--) {
        solve();
    }
    return 0;
}