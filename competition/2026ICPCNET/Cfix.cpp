#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        /*
            g[u] 保存所有满足 u -> v 的点 v。

            u -> v 表示：
            p[u] 必须小于 p[v]，
            因此下标 u 必须比下标 v 更早进入拓扑序。
        */
        vector<vector<int>> g(n + 1);

        // deg[i] 表示点 i 当前的入度
        vector<int> deg(n + 1, 0);

        while (m--) {
            int l, r;
            cin >> l >> r;

            // 当前约束一共包含 k 个下标
            int k = r - l + 1;

            /*
                例如输入：

                2 4  4 2 3

                表示：
                p[4] < p[2] < p[3]

                建边：
                4 -> 2
                2 -> 3
            */
            int pre;
            cin >> pre; // 先读 q 中的第一个下标

            for (int i = 1; i < k; ++i) {
                int cur;
                cin >> cur; // 读 q 中的下一个下标

                /*
                    p[pre] < p[cur]，
                    所以建立 pre -> cur。
                */
                g[pre].push_back(cur);

                // cur 多了一个必须排在它前面的点
                ++deg[cur];

                // 准备连接下一对相邻下标
                pre = cur;
            }
        }

        /*
            小根堆维护当前所有入度为 0 的点。

            入度为 0：
            这个点目前没有未完成的前置条件，可以选择。

            使用小根堆：
            每次选择编号最小的合法下标，使逆序数最少。
        */
        priority_queue<int, vector<int>, greater<int>> pq;

        // 把所有初始入度为 0 的点加入小根堆
        for (int i = 1; i <= n; ++i) {
            if (deg[i] == 0) {
                pq.push(i);
            }
        }

        /*
            ord 保存拓扑序。

            ord 中记录的是下标，而不是 p 中的值。

            如果：
            ord = [1, 4, 2, 3, 5]

            表示：
            p[1] < p[4] < p[2] < p[3] < p[5]
        */
        vector<int> ord;

        while (!pq.empty()) {
            // 取出当前编号最小的零入度点
            int u = pq.top();
            pq.pop();

            // 把这个下标加入拓扑序
            ord.push_back(u);

            /*
                相当于从图中删除 u。

                删除边 u -> v 后，
                v 就少了一个前置条件，所以入度减一。
            */
            for (int v : g[u]) {
                --deg[v];

                /*
                    v 的入度变成 0，
                    说明它的所有前置条件都完成了。
                */
                if (deg[v] == 0) {
                    pq.push(v);
                }
            }
        }

        /*
            如果拓扑序长度不足 n，说明图中存在环。

            例如：
            1 -> 2
            2 -> 1

            对应：
            p[1] < p[2] < p[1]

            显然无解。
        */
        if ((int)ord.size() < n) {
            cout << -1 << '\n';
            continue;
        }

        /*
            ord[i] 是第 i+1 个进入拓扑序的下标，
            所以给这个下标赋值 i+1。

            例如：
            ord = [1, 4, 2, 3, 5]

            那么：
            ans[1] = 1
            ans[4] = 2
            ans[2] = 3
            ans[3] = 4
            ans[5] = 5

            最终：
            ans = [1, 3, 4, 2, 5]
        */
        vector<int> ans(n + 1);

        for (int i = 0; i < n; ++i) {
            ans[ord[i]] = i + 1;
        }

        // 按照原下标 1~n 输出排列
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << " \n"[i == n];
        }
    }

    return 0;
}