#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll p;
    cin >> p;
    for(ll q=1;;q++){
        for(ll x2=1;x2<p;x2++){
            for(ll x1=1;x1<q;x1++){
                if(x1*x1%q==p%q && x2*x2%p==q%p){
                    cout << x1<< " "<<x2 <<" "<< p<<" "<<endl;
                    return;
                }
            }
        }
    }
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 999;
    // cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}