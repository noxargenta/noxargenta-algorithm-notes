#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long

void solve() {
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> g(n+1);
    vector<ll> deg(n+1,0);
    while(m--){
        ll l,r;
        cin >> l >> r;
        ll k=r-l+1;
        ll pre;
        cin >> pre;
        for(ll i=1;i<k;i++){
            
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