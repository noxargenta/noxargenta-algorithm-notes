#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define N 200005
vector<int> e[N];
int siz[N],vv[N],vis[N];
int ans,x,n,k;
void dfs1(int u,int fa){
    if(vis[u]==1){
        vv[u]=1;
    }
    siz[u]=1;
    for(auto v:e[u]){   
        if(v==fa)continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        vv[u]|=vv[v];
    }
}
void dfs2(int u,int fa){
    for(auto v:e[u]){
        if(v==fa)continue;
        if(vv[v]!=1){
            ans-=siz[v];
            continue;
        }else {
            dfs2(v,u);
        }
    }
}
void solve() {
    cin >> n >> k;
    ans=n;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    while(k--){
        cin >> x;
        vis[x]=1;
    }
    dfs1(x,0);
    dfs2(x,0);
    cout << ans << endl;
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