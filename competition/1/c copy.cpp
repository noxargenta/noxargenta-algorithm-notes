#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int t;
    cin >> t;
    for (int i=0;i<t;i++){
        int a,b;
        cin >> a >> b ;
        if ((a+b)%3 ==0 && (2*a -b)%3 == 0 && (2*b - a )%3==0 && 2*a >=b && 2*b >=a){
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