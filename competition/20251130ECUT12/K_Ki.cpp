#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
vector<int> G[200005];
int sum[200005];
int n,q;
void dfs(int x,int fa){
    for(auto i:G[x]){
        if(i==fa){
            continue;
        }
        sum[i]+=sum[x];
        dfs(i,x);
    }
}
void solve() {
    cin >> n >>q;
    for(int i=1;i<n;i++){
        int v,u;
        cin >> v >> u;
        G[v].push_back(u);
        G[u].push_back(v);
    }

    for(int i=1;i<=q;i++){
        int v,u;
        cin >> v >> u;
        sum[v]+=u;
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        cout << sum[i] << " ";
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