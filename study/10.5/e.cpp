#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int len_b = n - k;
    int r = 2e9 + 7; 
    for (int i = 0; i <= k; i++) {
        int c = a[i + len_b - 1] - a[i];
        r = min(r, c);
    }
    cout << r << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}