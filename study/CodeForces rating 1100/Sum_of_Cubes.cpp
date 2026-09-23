#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll x;
    cin >> x;
    for(ll i=1;i<=1e4;i++){
        ll need=x-i*i*i;
        if(need<=0)break;
        ll c=round(cbrt((double)need));
        if(c*c*c==need){
            cout << "YES\n";
            return;
        }
        

    }
    cout << "NO\n";
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