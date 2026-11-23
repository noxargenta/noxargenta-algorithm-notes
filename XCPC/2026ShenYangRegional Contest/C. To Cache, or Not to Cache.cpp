#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        long long A, B, C;  // 总花费可达 10^14，用 long long。
        cin >> n >> m >> A >> B >> C;

        // 把出现过的地址重新编号为 1 到 d，下标 0 留给空槽。
        vector<int> a(n), id(m + 1, 0);
        int d = 0;
        for (int& u : a) {
            cin >> u;
            if (id[u] == 0) id[u] = ++d;
            u = id[u];
        }

        const long long baseline = n * A;  // 全部直访的花费。
        if (A <= B) {  // A <= B <= C，每次直访都达到单次最低花费。
            cout << baseline << '\n';
            continue;
        }

        // 相对直访，命中节省 h，未命中节省 c。c 可以为负。
        const long long h = A - B, c = A - C;
        const long long NEG = -(1LL << 60);  // 表示状态不可达。
        // f[x][y] 是状态 (最近使用 x, 较久未用 y) 的最大节省量。
        // g[x] 是 f[x] 这一行的最大值。每组测试都重新初始化。
        vector<vector<long long>> f(d + 1, vector<long long>(d + 1, NEG));
        vector<long long> g(d + 1, NEG);
        f[0][0] = g[0] = 0;  // 开始时两个槽都空，节省量为 0。

        for (int i = 0; i < n; ) {
            int u = a[i], j = i + 1;
            while (j < n && a[j] == u) ++j;  // [i, j) 都在访问 u。

            int r = j - i;
            // 一旦本段走了缓存，u 就成为最近使用的地址。
            // 首次走缓存可以提前到段首，之后每次都能命中。
            long long all_hits = r * h;
            long long first_miss = c + (r - 1) * h;
            long long row_best = NEG;

            // 整段直访的节省量为 0，原状态可以保留。
            // 整段走缓存后，u 一定在第一槽，所以只更新第 u 行。
            for (int x = 0; x <= d; ++x) {
                if (x == u) continue;  // 同一个地址不能占两个槽。

                // 段首命中 u，旧状态可以是 (u,x) 或 (x,u)。
                // 从 (u,x) 全段命中比整段直访多省 r*h，且终点相同。
                long long hit_start = max(f[u][x], f[x][u]);
                long long value = NEG;
                if (hit_start != NEG) value = hit_start + all_hits;

                // 段首未命中 u，旧第一槽 x 留在第二槽。
                // 若 g[x] 恰好来自 (x,u)，上面的合法命中候选
                // 至少一样好，因为 h >= c，所以仍可直接用 g[x]。
                if (g[x] != NEG) value = max(value, g[x] + first_miss);

                // 这里只读本格旧值和其他行，可以直接写回本格。
                f[u][x] = value;
                row_best = max(row_best, value);
            }
            g[u] = row_best;  // 整行更新完，再记录新的行最大值。
            i = j;
        }

        cout << baseline - *max_element(g.begin(), g.end()) << '\n';
    }
}