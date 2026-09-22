#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> c(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        // 算出每个元素的不变特征值 c[i] = a[i] - (下标)
        // 题目是 1-indexed，所以减去 (i + 1)
        c[i] = a[i] - (i + 1);
    }

    // 排序并去重（因为连续序列中每个数只能用一次）
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());

    // 寻找最长的公差为 1 的连续递增子段
    int max_len = 1;
    int cur_len = 1;
    for (size_t i = 1; i < c.size(); ++i) {
        if (c[i] == c[i - 1] + 1) {
            cur_len++;
        } else {
            cur_len = 1;
        }
        max_len = max(max_len, cur_len);
    }

    cout << max_len << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}