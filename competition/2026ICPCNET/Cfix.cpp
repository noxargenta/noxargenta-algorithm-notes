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

        // 使用链式前向星存图，避免大量 vector 的小内存分配
        vector<int> head(n + 1, -1);
        vector<int> indegree(n + 1, 0);

        vector<int> to;
        vector<int> nextEdge;

        auto addEdge = [&](int u, int v) {
            to.push_back(v);
            nextEdge.push_back(head[u]);
            head[u] = static_cast<int>(to.size()) - 1;
            ++indegree[v];
        };

        for (int i = 0; i < m; ++i) {
            int l, r;
            cin >> l >> r;

            int length = r - l + 1;

            int previous;
            cin >> previous;

            // 只连接 q 中相邻的元素
            for (int j = 1; j < length; ++j) {
                int current;
                cin >> current;

                addEdge(previous, current);
                previous = current;
            }
        }

        // 维护当前所有入度为 0 的点
        priority_queue<int, vector<int>, greater<int>> heap;

        for (int i = 1; i <= n; ++i) {
            if (indegree[i] == 0) {
                heap.push(i);
            }
        }

        vector<int> p(n + 1);

        int assignedValues = 0;

        while (!heap.empty()) {
            int u = heap.top();
            heap.pop();

            // u 是第 assignedValues + 1 小的位置
            p[u] = ++assignedValues;

            for (int edge = head[u];
                 edge != -1;
                 edge = nextEdge[edge]) {

                int v = to[edge];

                --indegree[v];

                if (indegree[v] == 0) {
                    heap.push(v);
                }
            }
        }

        // 没有处理完所有点，说明有环
        if (assignedValues != n) {
            cout << -1 << '\n';
            continue;
        }

        for (int i = 1; i <= n; ++i) {
            if (i > 1) {
                cout << ' ';
            }
            cout << p[i];
        }

        cout << '\n';
    }

    return 0;
}