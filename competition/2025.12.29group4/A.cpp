#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<vector<int>> g(n+1);
    for(int i=1;i<=m;i++){
        int x ,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> vis(n+1,-1),ans(k+1,0);
    queue<int> q;
    vis[1]=0;
    
    q.push(1);
    while(q.size()){
        int u=q.front();
        q.pop();
        for(auto v : g[u]){
            if(vis[v]==-1){
                q.push(v);
                vis[v]=vis[u]+1;
                ans[a[v]]=max(ans[a[v]],vis[v]);
            }
        }
    }
    for(int i=1;i<=k;i++){
        cout << ans[i] << " ";
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