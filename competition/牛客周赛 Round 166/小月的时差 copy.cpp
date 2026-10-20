#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long

void solve() {
    int n, m, a, b, s, t;
    cin >> n >> m >> a >> b >> s >> t;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // 求起点到所有结点的最短距离
    auto bfs = [&](int start) {
        vector<int> d(n + 1, -1);
        queue<int> q;
        d[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : g[u]) {
                if (d[v] != -1) continue;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
        return d;
    };

    auto da = bfs(a);
    auto db = bfs(b);

    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) {
        c[i] = abs(da[i] - db[i]); // 每个点的时差
    }

    // dist[u]：从 s 到 u，最小的“沿途最大时差”
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    dist[s] = c[s];
    pq.push({dist[s], s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue;
        if (u == t) break;

        for (int v : g[u]) {
            int nd = max(d, c[v]); // 经过 v 后的最大时差
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }

    cout << dist[t] << endl;
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}
