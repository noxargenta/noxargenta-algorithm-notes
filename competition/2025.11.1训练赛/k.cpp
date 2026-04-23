#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    for (int i = 0;i<n;i++) {
        int t;
        cin >> t;
        if (t >= 0 && t <= n) {
            a[t]++;
        }
    }
    int miss = 0;
    for (int i = 0; i < k; i++) {
        if (a[i] == 0) {
            miss++;
        }
    }
    int ck = a[k];
    cout << max(miss, ck) << endl;
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}
