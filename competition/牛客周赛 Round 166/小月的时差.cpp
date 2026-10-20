#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
ll n,m,a,b,s,t;
vector<vector<ll>> G(2e5+10);
vector<ll> x(2e5+10,0);
vector<ll> y(2e5+10,0);
vector<ll> c(2e5+10,0);
void solve() {
    cin >> n >> m >> a >> b >> s >> t;
    for(ll i=1;i<=m;i++){
        ll u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
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