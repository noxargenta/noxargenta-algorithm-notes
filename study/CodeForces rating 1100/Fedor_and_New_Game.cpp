#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> a(m);
    for(ll i=0;i<m;i++){
        cin  >> a[i];
    }
    ll val=0;
    cin >> val;
    for(ll i=0;i<m;i++){
        ll now=val^a[i];
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