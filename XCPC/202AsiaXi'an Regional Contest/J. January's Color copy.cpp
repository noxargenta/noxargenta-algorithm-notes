#include <bits/stdc++.h>
using namespace std;

// 费用和路径前缀和可能超过 int，统一使用 long long。
using i64 = long long;
using ll = long long;

// 当作“无穷大”，表示还没有找到对应的最小值。
const ll INF = LLONG_MAX;

// 处理一组测试数据。
void solve() {
    int n, m;
    cin >> n >> m;

    // c[u]：直接从银行购买节点 u 的费用。
    vector<ll> c(n + 1);
    for (int u = 1; u <= n; ++u) {
        cin >> c[u];
    }

    // G[u]：节点 u 的邻接节点列表，用来存储无向树。
    vector<vector<int>> G(n + 1);

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    // parent[u]：以 1 为根时，u 的父节点。
    // 根节点 1 的父节点设为 0。
    vector<int> parent(n + 1, 0);

    // tin[u]：节点 u 在 DFS 先序遍历中的位置。
    // 用于快速判断一个节点是否为另一个节点的祖先。
    vector<int> tin(n + 1);

    // sz[u]：以 u 为根的子树大小。
    // 初始每个节点至少包含它自己。
    vector<int> sz(n + 1, 1);

    // order：DFS 访问节点的先序顺序。
    // 逆序遍历它，就能先处理孩子，再处理父亲。
    vector<int> order;
    order.reserve(n);

    // st：手动维护的 DFS 栈，避免递归过深导致栈溢出。
    vector<int> st;
    st.reserve(n);
    st.push_back(1);

    // 栈模拟 DFS，计算 parent、tin 和 order。
    while (!st.empty()) {
        int u = st.back();
        st.pop_back();

        // 当前节点在 DFS 先序中的编号。
        tin[u] = static_cast<int>(order.size());
        order.push_back(u);

        for (int v : G[u]) {
            // 无向树中跳过父节点，避免走回头路。
            if (v == parent[u]) continue;

            parent[v] = u;
            st.push_back(v);
        }
    }

    // f[u]：从空手开始，最终只获得节点 u 的最低费用。
    vector<ll> f(n + 1);

    // mn1[u]：u 的孩子中，f 值最小的费用。
    vector<ll> mn1(n + 1, INF);

    // mn2[u]：u 的孩子中，f 值第二小的费用。
    // 需要两个不同的孩子才能合成 u。
    vector<ll> mn2(n + 1, INF);

    // best[u]：对应 mn1[u] 的那个孩子的编号。
    // 后面计算某个孩子的兄弟费用时，需要排除它自己。
    vector<int> best(n + 1, -1);

    // 逆序处理节点：先算孩子，再算父亲。
    // 同时计算每个节点的子树大小和 DP 值。
    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];

        // 直接购买 u 是一种获取方式。
        f[u] = c[u];

        // 遍历 u 的所有孩子。
        for (int v : G[u]) {
            if (parent[v] != u) continue;

            // v 的子树包含在 u 的子树中。
            sz[u] += sz[v];

            // 更新孩子 DP 费用中最小的两个值。
            if (f[v] < mn1[u]) {
                mn2[u] = mn1[u];
                mn1[u] = f[v];
                best[u] = v;
            } else if (f[v] < mn2[u]) {
                mn2[u] = f[v];
            }
        }

        // 如果 u 至少有两个孩子，可以分别获得两个孩子后合成 u。
        // 选择费用最低的两个孩子即可。
        if (mn2[u] != INF) {
            f[u] = min(f[u], mn1[u] + mn2[u]);
        }
    }

    // D[u]：从根节点 1 到 u 的路径边权和。
    // 它用于快速计算祖先 y 到节点 x 之间的费用。
    vector<ll> D(n + 1, 0);

    // 按先序计算路径前缀和，保证父节点的 D 值已经计算。
    for (int u : order) {
        if (u == 1) continue;

        int p = parent[u];

        // 从 u 合成到父亲 p，需要再获得一个不同的兄弟节点。
        // 若 u 正好是 p 的最便宜孩子，就使用次便宜孩子；
        // 否则使用最便宜孩子。
        ll w;
        if (best[p] == u) {
            w = mn2[p];
        } else {
            w = mn1[p];
        }

        // 根到 u 的路径费用 = 根到父亲的费用 + u 到父亲这一步的费用。
        D[u] = D[p] + w;
    }

    // 逐个回答询问。
    while (m--) {
        int x, y;
        cin >> x >> y;

        // DFS 先序中，y 的整棵子树是一段连续区间：
        // [tin[y], tin[y] + sz[y] - 1]。
        // 如果 x 在这段区间内，则 y 是 x 的祖先。
        bool isAncestor =
            tin[y] <= tin[x] &&
            tin[x] < tin[y] + sz[y];

        if (!isAncestor) {
            // 只能从节点向父亲合成，不能向下拆分，所以 y 不是 x 的祖先时无解。
            cout << -1 << '\n';
        } else {
            // 两个根路径前缀相减，得到从 x 向上合成到 y 的费用。
            cout << D[x] - D[y] << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 测试用例数量。
    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}