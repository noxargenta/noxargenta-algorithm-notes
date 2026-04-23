#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
const int INF=2e5+9;
#define int long long
int n,m,cnt,sum,a[INF],b[INF];
bool vis[INF];
vector<int> G[INF];
void dfs(int x){
    if(!vis[x]){
        sum++;
        vis[x]=1;
        for(auto y : G[x]){
            cnt++;
            if(!vis[y]){
                dfs(y);
            }
        }
    }
}
void solve( ) {
    cin >> n >> m;
    int ans=0;
    for(int i=1;i<=m;i++){
        int x, y;
        cin >> x >> y;
        a[i]=x;b[i]=y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cnt=0;
            sum=0;
            dfs(i);
            ans+=sum*(sum-1)/2-(cnt/2);
        }
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