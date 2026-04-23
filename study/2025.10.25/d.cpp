#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    for(int i=0;i<n;i++){
        int val;
        cin >> val;
        a[i+1]=a[i]+val;
    }
    int m;
    cin >> m ;
    int r,l;
    for(int i=0;i<m;i++){
        cin >> l >> r;
        cout << a[r]-a[l-1] << " ";
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