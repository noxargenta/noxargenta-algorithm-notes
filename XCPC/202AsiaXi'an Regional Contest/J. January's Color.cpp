#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    const ll INF = (1LL << 62);

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<ll> c(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> c[i];
        }

        vector<vector<int>> adj(n + 1);

        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> parent(n + 1, 0);
        vector<int> tin(n + 1);
        vector<int> sz(n + 1, 1);

        vector<int> order;
        order.reserve(n);

        vector<int> st;
        st.reserve(n);
        st.push_back(1);

        // 1. 栈模拟 DFS，求父亲和 DFS 先序。
        while (!st.empty()) {
            int u = st.back();
            st.pop_back();

            tin[u] = (int)order.size();
            order.push_back(u);

            for (int v : adj[u]) {
                if (v == parent[u]) continue;

                parent[v] = u;
                st.push_back(v);
            }
        }

        vector<ll> f(n + 1);
        vector<ll> mn1(n + 1, INF);
        vector<ll> mn2(n + 1, INF);

        // best[u]：最小值 mn1[u] 对应的孩子。
        vector<int> best(n + 1, -1);

        // 2. 逆序计算树形 DP 和子树大小。
        for (int i = n - 1; i >= 0; --i) {
            int u = order[i];

            f[u] = c[u];

            for (int v : adj[u]) {
                if (parent[v] != u) continue;

                sz[u] += sz[v];

                if (f[v] < mn1[u]) {
                    mn2[u] = mn1[u];
                    mn1[u] = f[v];
                    best[u] = v;
                } else if (f[v] < mn2[u]) {
                    mn2[u] = f[v];
                }
            }

            // 非叶子节点：也可以用两个孩子合成。
            if (mn2[u] != INF) {
                f[u] = min(f[u], mn1[u] + mn2[u]);
            }
        }

        vector<ll> D(n + 1, 0);

        // 3. 从根向下计算边权前缀和。
        for (int u : order) {
            if (u == 1) continue;

            int p = parent[u];

            // 获取最便宜的兄弟，不能选择 u 自己。
            ll w;
            if (best[p] == u) {
                w = mn2[p];
            } else {
                w = mn1[p];
            }

            D[u] = D[p] + w;
        }

        // 4. 回答询问。
        while (m--) {
            int x, y;
            cin >> x >> y;

            bool isAncestor =
                tin[y] <= tin[x] &&
                tin[x] < tin[y] + sz[y];

            if (!isAncestor) {
                cout << -1 << '\n';
            } else {
                cout << D[x] - D[y] << '\n';
            }
        }
    }

    return 0;
}