#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
const int N=3050;
vector<int> G[N];
int dp[N][N];
const int MOD=998244353;
int n;
void dfs(int u,int fa){
    if(G[u].size()==1 && fa!=0){
        dp[u][1]=1;
        return;
    }
    for(auto v : G[u]){
        if(v==fa)continue;
        dfs(v,u);
    }
    for(int i=0;i<n;i++){
        int a=1,b=1;
        for(auto v:G[u]){
            if(v==fa)continue;
            a=a*dp[v][i+1]%MOD;
            if(i>0){
                b=b*dp[v][i-1]%MOD;
            }
            
        }
    }
}
void solve() {
    for(int i=0;i<N;i++){
        G[i].clear();
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dp[i][j]=0;
        }
    }
    cin >> n;
    for(int i=1;i<=n;i++){
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(n==1){
        cout << 0 << endl;
    }else {
        dfs(1,0);
        cout << dp[1][0];
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