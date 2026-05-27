#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int n,m;
int dx[] = {-1,0,1,0,1,1,-1,-1};
int dy[] = {0,1,0,-1,1,-1,1,-1};
char a[101][101];
bool vis[101][101];
int ans=0;
void dfs(int x,int y){
    if(vis[x][y]  || x < 0 || x >=n  || y<0 || y>=m){
        return;
    }else {
        vis[x][y]=1;
    }
    for(int i=0;i<8;i++){
        if(x+dx[i] < 0 || x+dx[i] >=n  || y+dy[i]<0 || y+dy[i]>=m){
            continue;
        }
        if(a[x+dx[i]][y+dy[i]]=='W' || vis[x+dx[i]][y+dy[i]]==0){
            dfs(x+dx[i],y+dy[i]);
        }  
    }
}
void solve() {
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
            if(a[i][j]=='.'){
                vis[i][j]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j] )continue;
            ans++;
            dfs(i,j);
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