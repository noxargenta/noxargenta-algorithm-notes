#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >>n;
    for(int i=0;i<n;i++){
        vector<int> a(3);
        for(int j=0;j<3;j++){
            cin >> a[j];
        }
        sort(a.begin(),a.end());
        if(a[2]==a[0]+a[1]){
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
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