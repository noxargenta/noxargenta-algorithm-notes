#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n,m,a,b,s,t;
    cin >> n >> m >> a >> b >> s >> t;
    vector<vector<ll>> G(n+1);
    for(ll i=0;i<m;i++){
        ll u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    auto bfs = [&](ll start){
        vector<ll> d(n+1,-1);
        queue<ll> q;
        d[start]=0;
        q.push(start);

        while(!q.empty()){
            ll u = q.front();
            q.pop();

            for(auto v : g[u]){
                
            }
        }
    }
    G[v].push_back(u);
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