#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int n,m,k;
vector<int> G[300005];
int dist[300005];
void solve(){
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        int v ,u;
        cin >> v >> u;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    fill(dist+1,dist+n+1,-1);
    queue<int> q;
    for(int i=1;i<=k;i++){
        int x;
        cin >> x;
        dist[x]=0;
        q.push(x);
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto v : G[x]){
            if(dist[v]==-1){
                q.push(v);
                dist[v]=dist[x]+1;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(dist[i]==-1){
            cout << -1 << endl;
            return;
        }else {
            ans=max(ans,dist[i]);
        }
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _=1;
    //cin >> _;
    while(_--){
        solve();
    }
}