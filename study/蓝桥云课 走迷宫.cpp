#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int n,m;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int G[300][300];
int vis[300][300];
int dist[300][300];
void solve() {
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> G[i][j];
            if(G[i][j]==0){
                vis[i][j]=1;
            }
        }
    }
    int x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--;
    y1--;
    x2--;
    y2--;
    queue<pair<int,int>> q;
    q.push({x1,y1});
    dist[x1][y1]=0;
    vis[x1][y1]=1;
    while(!q.empty()){
        int xx=q.front().first,yy=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int xx2=xx+dx[i];
            int yy2=yy+dy[i];    
            if(xx2<0 || xx2>=n || yy2<0 || yy2 >=m)continue;
            if(!vis[xx2][yy2]){
                dist[xx2][yy2]=dist[xx][yy]+1;
                if(xx2==x2 && yy2==y2){
                    cout << dist[xx2][yy2] << endl;
                    return;
                }
                q.push({xx2,yy2});
                vis[xx2][yy2]=1;

            }   
        }
    }
    cout << -1 << endl;
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