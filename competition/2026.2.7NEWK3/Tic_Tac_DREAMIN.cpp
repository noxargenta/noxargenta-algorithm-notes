#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int y11,y22,x11,x22;
    cin >> x11 >> y11 >> x22 >> y22;
    if(y11==y22){
        if(abs(abs(y11)*abs(x22-x11)-4.0)<=1e-9){
            cout << 0 << endl;
            return;
        }else {
            cout << "no answer\n";
            return;
        }
    }
    double x=(4.0-x11*y22+x22*y11)/(y11-y22);
    cout << fixed<< setprecision(10)  << x << endl;
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