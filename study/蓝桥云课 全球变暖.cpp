#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool vis[1010][1010];
int n;
int ans=0;
char a[1010][1010];
bool gd = false;
void dfs(int x,int y){
    vis[x][y] = 1;
    bool flag = false;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < n){
            if(a[nx][ny] == '.'){
                flag = true;
            }
        }
    }
    if(!flag) gd = true;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || nx>=n || ny<0 || ny>=n){
            continue;
        }
        if(vis[nx][ny]==0 && a[nx][ny]=='#'){
            dfs(nx,ny);
        }
    }
}
void solve() {
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] == '#' && !vis[i][j]) {
                gd = false;
                dfs(i,j);
                if(!gd) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while(_--) {
        solve();
    }
    return 0;
}
