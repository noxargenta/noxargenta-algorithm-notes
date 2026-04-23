#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n,k,x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    vector<int> b;
    for (int i=0; i<k; i++){
        b.push_back(a[i]);
    }
    b.push_back(x);
    for (int i=k; i<n; i++){
        b.push_back(a[i]);
    }
    for (int i=0; i<b.size(); i++){
        cout << b[i] << (i==b.size()-1 ? "" : " ");
    }
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}