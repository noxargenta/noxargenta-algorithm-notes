#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> dep(n + 1);
    int root = -1, cntRoot = 0;

    for (int i = 1; i <= n; i++) {
        cin >> dep[i];
        if (dep[i] == 0) {
            root = i;
            cntRoot++;
        }
    }

    vector<vector<int>> g(n + 1);
    vector<pair<int, int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.push_back({u, v});
    }

    if (cntRoot != 1) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> parent(n + 1, -1);
    bool ok = true;

    for (int u = 1; u <= n; u++) {
        if (u == root) continue;

        int cnt = 0;
        for (int v : g[u]) {
            if (dep[v] == dep[u] - 1) {
                parent[u] = v;
                cnt++;
            }
        }

        if (cnt != 1) {
            ok = false;
            break;
        }
    }

    if (!ok) {
        cout << -1 << '\n';
        return 0;
    }

    int LOG = 1;
    while ((1 << LOG) <= n) LOG++;

    vector<vector<int>> up(LOG, vector<int>(n + 1, -1));

    up[0][root] = -1;
    for (int u = 1; u <= n; u++) {
        if (u != root) up[0][u] = parent[u];
    }

    for (int k = 1; k < LOG; k++) {
        for (int u = 1; u <= n; u++) {
            int p = up[k - 1][u];
            if (p != -1) up[k][u] = up[k - 1][p];
        }
    }

    auto isAncestor = [&](int u, int v) {
        // 要求 u 的深度不大于 v
        if (dep[u] > dep[v]) return false;

        int diff = dep[v] - dep[u];

        for (int k = 0; k < LOG; k++) {
            if (diff & (1 << k)) {
                v = up[k][v];
            }
        }

        return u == v;
    };

    for (auto [u, v] : edges) {
        if (dep[u] == dep[v]) {
            ok = false;
            break;
        }

        if (dep[u] < dep[v]) {
            if (!isAncestor(u, v)) {
                ok = false;
                break;
            }
        } else {
            if (!isAncestor(v, u)) {
                ok = false;
                break;
            }
        }
    }

    if (!ok) {
        cout << -1 << '\n';
        return 0;
    }

    vector<vector<int>> ans(n + 1);

    // 先放 DFS 树边，再放非树边
    for (int u = 1; u <= n; u++) {
        for (int v : g[u]) {
            if (parent[v] == u) {
                ans[u].push_back(v);
            }
        }

        for (int v : g[u]) {
            if (parent[v] != u) {
                ans[u].push_back(v);
            }
        }
    }

    cout << root << '\n';
    for (int u = 1; u <= n; u++) {
        for (int v : ans[u]) {
            cout << v << ' ';
        }
        cout << '\n';
    }

    return 0;
}