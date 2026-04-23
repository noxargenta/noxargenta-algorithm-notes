#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >> n;
    for(int i=1;i<4;i++){
        int t;
        cin >> t;
        if(t != n){
            cout << "NO\n";
            for(int j=0;j<3-i;j++){
                int un;
                cin >> un;
            }
            return;
        }
    }
    cout << "YES\n";
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