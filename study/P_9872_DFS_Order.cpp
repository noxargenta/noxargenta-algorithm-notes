#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
const int N=1e6+9;
vector<int> G[N];
int siz[N],dep[N];
int n;
void dfs(int u,int f){
    dep[u]=dep[f]+1;
    siz[u]=1;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v == f){
            continue;
        }
        dfs(v,u),siz[u]+=siz[v];
    }
    return;
}
void solve() {
    cin >> n;
    for(int i=0;i<=n;i++){
        G[i].clear();
    }
    for(int i=1,x,y;i<n;i++){
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        cout << dep[i] << ' ' << n-siz[i] +1 << endl;
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