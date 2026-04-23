#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n,m;
    cin >> n >> m;
    vector <int > a(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int max_gift=0;
    int r=0,l=0;
    for (;l<n; l++){
        for (;r<n && a[r] < a[l] + m ;r++){
            max_gift=max(r-l+1,max_gift);
        }
    }
    cout << max_gift;
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