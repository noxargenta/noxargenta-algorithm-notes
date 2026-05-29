#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int n,m,x,y;
int dx[]={1,2,2,1,-1,-2,-2-1};
int dy[]={-2,-1,1,2,2,1,-1,-2};
bool vis[405][405];
int dis[405][405];
int g[405][405];
queue<pair<int,int>> q;
void solve() {
    cin >> n >> m >> x >>y;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cin >> g[i][j];
    //     }
    // }
    dis[x][y]=0;
    vis[x][y]=1;
    q.push({x,y});
    while(!q.empty()){
        int xx=q.front().first;
        int yy=q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int x2=xx+dx[i];
            int y2=yy+dy[i];
            if(!vis[x2][y2]){
                vis[x2][y2]=1;
                dis[x2][y2]=dis[xx][yy]+1;
                
                q.push({x2,y2});
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dis[i][j]==0){
                cout << -1 << ' ';
            }else {
                cout << dis[i][j] << " " ;
            }
        }
        cout << endl;
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