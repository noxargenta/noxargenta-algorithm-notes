#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<vector<int>> g(n+1);
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int> q;
    vector<int> vis(n+1,-1),ans(k+1,0),type(k+1);
    vis[1]=0;
    type[a[0]]=max(type[a[0]],vis[0]);
    q.push(1);
    while(q.size()){
        int u=q.front();
        q.pop();
        for(auto v:g[u]){
            if(vis[v]==-1){
                vis[v]=vis[u]+1;
                int type=a[v];
                ans[type]=max(ans[type],vis[v]);
                q.push(v);
            }
        }
    }
    for(int i=1;i<=k;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
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