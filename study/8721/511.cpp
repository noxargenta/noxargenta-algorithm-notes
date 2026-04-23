#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    double x;
    cin >> x;
    double e=1.0-x;
    if(x==1){
        cout << "Sorrry,JuJu!";
    }else {
        i64 res =round(e*10000000);
        i64 res2=10000000;
        int w=__gcd(res,res2);
        cout << res2/w << "/" << res/w;
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