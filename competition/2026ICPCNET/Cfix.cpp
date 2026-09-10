#include <bits/stdc++.h>
using namespace std;

int main() {
    // 关闭 C 与 C++ 输入输出同步，提高 cin/cout 速度
    ios::sync_with_stdio(false);

    // 解除 cin 与 cout 的绑定，进一步加速输入
    cin.tie(nullptr);

    // 测试用例数量
    int T;
    cin >> T;

    // 依次处理每组测试数据
    while (T--) {
        // n：排列长度，m：约束数量
        int n, m;
        cin >> n >> m;

        /*
            链式前向星存图。

            hd[u] 表示点 u 的第一条出边编号。
            如果 hd[u] == -1，说明 u 没有出边。
        */
        vector<int> hd(n + 1, -1);

        /*
            in[v] 表示点 v 当前的入度。

            如果 in[v] == 0，说明当前没有任何点
            必须排在 v 前面，此时 v 可以进入拓扑序。
        */
        vector<int> in(n + 1, 0);

        /*
            第 e 条边的信息：

            to[e]  ：第 e 条边指向的终点
            nxt[e] ：与第 e 条边起点相同的下一条边
        */
        vector<int> to;
        vector<int> nxt;

        /*
            加入一条有向边 u -> v。

            在本题中，它表示：
            p[u] < p[v]
        */
        auto add = [&](int u, int v) {
            // 记录这条边的终点 v
            to.push_back(v);

            // 新边的下一条边，是原本 u 的第一条边
            nxt.push_back(hd[u]);

            // 更新 u 的第一条边编号
            hd[u] = (int)to.size() - 1;

            // 因为多了一条指向 v 的边，所以 v 的入度加一
            ++in[v];
        };

        // 读取 m 条约束
        while (m--) {
            // 当前约束对应的连续区间 [l,r]
            int l, r;
            cin >> l >> r;

            // 当前区间的长度
            int len = r - l + 1;

            /*
                q 中的第一个下标。

                因为 len >= 1，所以一定存在第一个数。
            */
            int pre;
            cin >> pre;

            /*
                对于约束：

                p[q1] < p[q2] < ... < p[q_len]

                只需要加入：

                q1 -> q2
                q2 -> q3
                ...
                q_(len-1) -> q_len

                一共 len-1 条边。
            */
            for (int i = 1; i < len; ++i) {
                // 当前读到的 q 下标
                int cur;
                cin >> cur;

                /*
                    pre 在 cur 前面，表示：

                    p[pre] < p[cur]

                    因此加入 pre -> cur。
                */
                add(pre, cur);

                // 当前元素成为下一次循环的前一个元素
                pre = cur;
            }
        }

        /*
            小根堆。

            pq 中保存当前所有入度为 0 的点，
            每次取出编号最小的点。
        */
        priority_queue<int, vector<int>, greater<int>> pq;

        // 将所有初始入度为 0 的点加入小根堆
        for (int i = 1; i <= n; ++i) {
            if (in[i] == 0) {
                pq.push(i);
            }
        }

        /*
            ans[i] 表示最终排列中的 p[i]。

            如果下标 u 是拓扑序中的第 k 个点，
            就令 ans[u] = k。
        */
        vector<int> ans(n + 1, 0);

        // cnt 表示已经完成拓扑排序的点数
        int cnt = 0;

        // Kahn 拓扑排序
        while (!pq.empty()) {
            // 取出当前编号最小的零入度点
            int u = pq.top();
            pq.pop();

            /*
                u 是拓扑序中的第 cnt+1 个点。

                也就是说，p[u] 应该是当前尚未使用的最小值。
            */
            ans[u] = ++cnt;

            /*
                枚举 u 的所有出边。

                hd[u] 是第一条出边；
                nxt[e] 是下一条出边；
                e == -1 时枚举结束。
            */
            for (int e = hd[u]; e != -1; e = nxt[e]) {
                // 第 e 条边为 u -> v
                int v = to[e];

                /*
                    将 u 从剩余图中删除。

                    对于边 u -> v，相当于 v 少了一个前驱，
                    所以 v 的入度减一。
                */
                --in[v];

                /*
                    如果 v 的入度变成 0，
                    说明 v 的所有前置要求都已经处理完，
                    可以加入小根堆。
                */
                if (in[v] == 0) {
                    pq.push(v);
                }
            }
        }

        /*
            如果 cnt < n，说明有一些点始终无法变成零入度点。

            这些点位于有向环中，因此约束互相矛盾，无解。
        */
        if (cnt < n) {
            cout << -1 << '\n';
            continue;
        }

        // 输出最终排列 p
        for (int i = 1; i <= n; ++i) {
            // 除第一个数字外，每个数字前输出一个空格
            if (i > 1) {
                cout << ' ';
            }

            // ans[i] 就是 p[i]
            cout << ans[i];
        }

        // 当前测试用例输出结束
        cout << '\n';
    }

    // 程序正常结束
    return 0;
}