#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n,l;
    cin >> n >> l;
    int a[n];
    vector<int> l(n);
    vector<double> 
    for(int i=0;i<n;i++){
        l[i]=1;
    }
    for(int i=0;i<n;i++){
        cin >> a[i];
        int l=1;
        for(int j=0;j<n;j++){
            l*=2;
        }
        double t=double(a[i]/l);
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