#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(2 * n);
    vector<vector<int>> pos(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
        pos[a[i]].push_back(i);
    }

    // 第一步：求每个位置右边第一个严格更大的元素。
    vector<int> to(n, -1);
    vector<int> len(n, n);
    vector<int> st;

    for (int i = 2 * n - 1; i >= 0; i--) {
        // <= 当前值的元素，不可能成为当前的“严格更大元素”。
        while (!st.empty() && a[st.back()] <= a[i]) {
            st.pop_back();
        }

        if (i < n && !st.empty()) {
            to[i] = st.back() % n;
            len[i] = st.back() - i;
        }

        st.push_back(i);
    }

    // pref[v]：数值 <= v 的位置数量。
    vector<int> pref(n + 1);
    for (int v = 1; v <= n; v++) {
        pref[v] = pref[v - 1] + (int)pos[v].size();
    }

    // 第二步：按数值从大到小计算排名。
    vector<int> rk(n);

    auto nextRank = [&](int i) -> int {
        if (to[i] == -1) return 0;
        return rk[to[i]];
    };

    for (int v = n; v >= 1; v--) {
        auto &ids = pos[v];

        sort(ids.begin(), ids.end(), [&](int x, int y) {
            if (len[x] != len[y]) {
                return len[x] > len[y];
            }
            return nextRank(x) < nextRank(y);
        });

        int rank = pref[v - 1];

        for (int k = 0; k < (int)ids.size(); k++) {
            int x = ids[k];

            // 与前一个结果不同，才分配一个新排名。
            if (k == 0) {
                rank++;
            } else {
                int y = ids[k - 1];

                if (len[x] != len[y] ||
                    nextRank(x) != nextRank(y)) {
                    rank++;
                }
            }

            rk[x] = rank;
        }
    }

    // 第三步：排名最小的位置，就是最优起点。
    int start = 0;
    for (int i = 1; i < n; i++) {
        if (rk[i] < rk[start]) {
            start = i;
        }
    }

    // 输出这个起点对应的前缀最大值。
    int mx = 0;
    for (int j = 0; j < n; j++) {
        mx = max(mx, a[start + j]);
        cout << mx << (j == n - 1 ? '\n' : ' ');
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }
}