#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
const int N=3050;
vector<int> G[N];
int dp[N][N];
const int MOD=998244353;
int dfs(int u,int fa){

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
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int u,v;
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
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}