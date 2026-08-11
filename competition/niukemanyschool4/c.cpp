#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll p;
    cin >> p;
    for(ll x=1;x*x<=1e9;x++){
        ll q=x*x-p;
        if(x*x % p==q && x * x %q==p){
            cout << x<<" " << x <<" "<< q<<" " <<endl;
            return;
        }
    }
    cout << "Impossible\n";
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