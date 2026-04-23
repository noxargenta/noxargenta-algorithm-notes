#include <bits/stdc++.h>
using namespace std;

struct Node {
    int l, r;
    bool operator>(const Node& other) const {
        return r > other.r;
    }
};

bool solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> range(n);
    for (int i = 0; i < n; i++) {
        int opt, x, y;
        cin >> opt;
        if (opt == 1) {
            cin >> x;
            range[i] = {x, n - 1};
        } else if (opt == 2) {
            cin >> x;
            range[i] = {0, x};
        } else {
            cin >> x >> y;
            range[i] = {x, y};
        }
    }

    sort(range.begin(), range.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        // 将所有左边界符合当前位置 i 的区间加入堆
        while (cur < n && range[cur].first <= i) {
            pq.push(range[cur].second);
            cur++;
        }
        
        // 如果当前位置没有可用区间，或者堆顶区间的右边界已经过期
        if (pq.empty() || pq.top() < i) return false;
        
        pq.pop(); // 分配掉截止日期最早的区间
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        if (solve()) cout << "Y" << endl;
        else cout << "N" << endl;
    }
    return 0;
}
