#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
const ll INF=LLONG_MAX;
#define ull unsigned long long
void solve() {
    ll n,m;
    cin >> n >> m;
    vector<ll> c(n+1);
    for(ll i=1;i<=n;i++){
        cin >> c[i];

    }
    vector<vector<ll>> G(n+1);
    for(ll i=1;i<n;i++){
        ll u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);

    }
    vector<ll> parent(n+1,0);
    vector<ll> tin(n+1);
    
    vector<ll> sz(n+1,1);
    vector<ll> order;
    order.reserve(n);

    stack<ll> st;
    st.push(1);
    while(!st.empty()){
        ll u=st.top();
        st.pop();

        tin[u]=order.size();
        order.push_back(u);
        for(ll v : G[u]){
            if(v== parent[u] )continue;
            parent[v]=u;
            st.push(v);
        }
    }
    vector<ll> f(n+1);
    vector<ll> mn1(n+1,INF);
    vector<ll> mn2(n+1,INF);
    vector<ll> best(n+1,-1);
    for(ll i=n-1;i>=0;i--){
        ll u=order[i];
        
        f[u]=c[u];
        
        for(auto v : G[u]){
            if(parent[v]!=u)continue;

            sz[u]+=sz[v];

            if(f[v]<mn1[u]){
                mn2[u] = mn1[u];
                mn1[u] = f[v];
                best[u] = v;
                
            }else if(f[v]<mn2[u]){
                mn2[u]=f[v];
            }
        }
        if(mn2[u]!=INF){
            f[u]=min(f[u],mn1[u]+mn2[u]);

        }
    }
    vector<ll> D(n+1,0);
    for(ll u : order){
        if(u==1)continue;
        ll p=parent[u];

        ll w;
        if(best[p]==u){
            w=mn2[p];

        }else {
            w=mn1[p];
        }
        D[u]=D[u]+w;

    }    
    while(m--){
        ll x,y;
        cin >> x >> y;
        bool ok= (tin[y] <= tin[x] && 
            tin[x]<tin[y] + sz[y]);
        if(!ok){
            cout << -1 <<endl;
        }else {
            cout << D[x]-D[y] <<endl;
        }
    }
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