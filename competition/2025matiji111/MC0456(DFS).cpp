#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
vector<int> G[1000006];
int n=0;int m=0;int ans=0;
int dfs(int x,int fa){
    int cur=1;
    vector<int> sons;
    for(auto i:G[x]){
        if(i==fa)continue;
        int son=dfs(i,x);
        sons.push_back(son);
    }
    sort(sons.begin(),sons.end());
    for(auto j : sons){
        if(cur+j<=m){
            cur+=j;
        }else {
            ans++;
        }
    }
    return cur;
}
void solve() {
    cin >> n >> m;
    int u,v;
    for(int i=1;i<n;i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(dfs(1,0)>0){
        ans++;
    }
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