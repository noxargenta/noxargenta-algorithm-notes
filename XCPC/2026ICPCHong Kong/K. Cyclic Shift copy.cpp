#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    // 把原数组复制一遍。
    //
    // 例如原数组：
    // 1 2 1 3
    //
    // 复制后：
    // 1 2 1 3 1 2 1 3
    //
    // 这样，从原数组的任意位置出发，
    // 连续读取 n 个数，就能得到对应的循环移位。
    vector<int> a(2 * n);

    // pos[v] 保存所有满足 a[i] == v 的原数组下标。
    // 后面需要按照数值从大到小，分组处理这些位置。
    vector<vector<int>> pos(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
        pos[a[i]].push_back(i);
    }

    /*
        第一步：求 to[i] 和 len[i]。

        例如：
        下标：0 1 2 3 4
        数值：2 1 2 3 1

        从位置 0 出发，前缀最大值是：
        2 2 2 3 3

        第一个严格大于 a[0] 的数在位置 3：
        to[0] = 3
        len[0] = 3

        所以前 len[0] 项都是 a[0]。
        从下一项开始，交给 to[0] 对应的结果继续处理。
    */

    // 如果不存在严格更大的元素：
    // to[i] = -1；
    // len[i] = n，表示整个答案都是 a[i]。
    //
    // 这种情况恰好发生在 a[i] 是全局最大值时。
    vector<int> to(n, -1);
    vector<int> len(n, n);

    // 单调栈：保存下标。
    // 从栈底到栈顶，对应的数值严格递减。
    vector<int> st;

    // 从右向左扫描复制后的数组。
    for (int i = 2 * n - 1; i >= 0; i--) {

        // 当前需要找的是：右边第一个严格大于 a[i] 的数。
        //
        // 栈顶如果 <= a[i]，就不能作为答案，弹出。
        //
        // 而且对于以后处理的更左侧位置，
        // 当前的 a[i] 比这些被弹出的数更近，且不小于它们，
        // 所以这些数也不需要再保留。
        while (!st.empty() && a[st.back()] <= a[i]) {
            st.pop_back();
        }

        // 弹完后，栈顶就是右边第一个严格更大的位置。
        //
        // 我们只需要记录原数组中 n 个位置的信息，
        // 因此只在 i < n 时更新。
        if (i < n && !st.empty()) {
            // 栈里可能存的是复制部分的下标，
            // 用 % n 映射回原数组。
            to[i] = st.back() % n;

            // 距离必须使用复制数组中的实际下标计算。
            len[i] = st.back() - i;
        }

        // 当前位置入栈，供更左侧的位置使用。
        st.push_back(i);
    }

    /*
        第二步：计算排名。

        比较两个起点 x、y，规则是：

        1. a[x] != a[y]：
           起点值较小的结果更小。

        2. a[x] == a[y]，但 len[x] != len[y]：
           len 较大的结果更小。
           因为它能让较小的最大值保持更久。

        3. 起点值和 len 都相同：
           比较后继结果，即 rk[to[x]] 和 rk[to[y]]。

        因为 a[to[i]] > a[i]，
        所以按数值从大到小处理时，
        后继位置的排名一定已经算好了。
    */

    // pref[v]：原数组中，值 <= v 的位置数量。
    vector<int> pref(n + 1, 0);

    for (int v = 1; v <= n; v++) {
        pref[v] = pref[v - 1] + (int)pos[v].size();
    }

    // rk[i] 越小，表示从位置 i 出发得到的结果越小。
    // 完全相同的结果，分配相同的排名。
    vector<int> rk(n, 0);

    // 获取位置 i 的后继排名。
    auto nextRank = [&](int i) -> int {
        // 没有后继，说明 a[i] 已经是全局最大值。
        // 此时整个前缀最大值序列都是 a[i]。
        //
        // 这些位置的 len 都是 n，结果全部相同，
        // 后继排名统一设置为 0 即可。
        if (to[i] == -1) {
            return 0;
        }

        return rk[to[i]];
    };

    // 按数值从大到小处理。
    for (int v = n; v >= 1; v--) {

        // ids 是所有满足 a[i] == v 的位置。
        // 引用可以避免复制整个 vector。
        auto &ids = pos[v];

        // 这一组起点的初始值都相同，
        // 所以只需要比较 len 和后继排名。
        sort(ids.begin(), ids.end(), [&](int x, int y) {
            if (len[x] != len[y]) {
                // 小的最大值保持得越久，结果越小。
                return len[x] > len[y];
            }

            // 保持长度也一样，就比较后面的结果。
            return nextRank(x) < nextRank(y);
        });

        /*
            给当前组分配排名。

            所有初始值小于 v 的位置，
            排名都必须小于当前组。

            初始值小于 v 的位置共有 pref[v - 1] 个，
            所以当前组从 pref[v - 1] + 1 开始分配排名。

            当前组最多有 pos[v].size() 种不同排名，
            因此不会超过 pref[v]。

            不同数值使用不同的排名区间，
            就能保证：初始值越小，排名一定越小。

            注意：排名允许有空缺，不要求连续。
        */
        int rank = pref[v - 1];

        for (int k = 0; k < (int)ids.size(); k++) {
            int x = ids[k];

            if (k == 0) {
                // 排序后的第一个位置，分配本组第一个排名。
                rank++;
            } else {
                int y = ids[k - 1];

                // 初始值相同的情况下，
                // len 和后继排名都相同，就表示结果相同。
                //
                // 只有结果不同，才增加排名。
                if (len[x] != len[y] ||
                    nextRank(x) != nextRank(y)) {
                    rank++;
                }
            }

            rk[x] = rank;
        }
    }

    // 第三步：找到排名最小的起点。
    // 如果有多个位置排名相同，任选一个即可。
    int start = 0;

    for (int i = 1; i < n; i++) {
        if (rk[i] < rk[start]) {
            start = i;
        }
    }

    // 第四步：从最优起点出发，输出前缀最大值。
    //
    // 因为已经复制过数组，
    // 所以直接访问 a[start + j]，不需要取模。
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