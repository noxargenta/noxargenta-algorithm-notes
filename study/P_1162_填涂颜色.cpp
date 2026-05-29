#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int n;
int vis[40][40];
int G[40][40];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
void bfs(int x1,int y1){
    queue<pair<int,int>> q;
    q.push({x1,y1});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx<=0 || xx >n  || yy<=0 || yy>n)continue;
            if(!vis[xx][yy] && G[xx][yy]==0){
                vis[xx][yy]=1;
                q.push({xx,yy});
            }
        }
    }
}
void bfs2(int x1,int y1){
    queue<pair<int,int>> q;
    q.push({x1,y1});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        G[x][y]=2;
        q.pop();
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx<=0 || xx >n  || yy<=0 || yy>n)continue;
            if(!vis[xx][yy] && G[xx][yy]==0){
                G[xx][yy]=2;
                q.push({xx,yy});
            }
        }
    }
}
void solve() {
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> G[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        if(i==1 || i==n){
            for(int j=1;j<=n;j++){
                if(G[i][j]==0){
                    bfs(i,j);
                }
            }
        }else {
            if(G[i][1]==0){
                bfs(i,1);
            }
            if(G[i][n]==0){
                bfs(i,n);
            }
        }
    }
    int inx=-1,iny=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(G[i][j]==0 && vis[i][j]==0){
                inx = i;
                iny = j;
                break;
            }
        }
        if(inx!=-1 && iny !=-1)break;
    }
    bfs2(inx,iny);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << G[i][j] << " ";
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