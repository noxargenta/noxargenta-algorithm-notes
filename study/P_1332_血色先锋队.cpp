#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int n,m,a,b;
queue<pair<int,int>> q;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int G[502][502];
int vis[502][502];
void bfs(){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx<=0 || xx>n || yy<=0 || yy>m || vis[xx][yy]==1)continue;
            G[xx][yy]=G[x][y]+1;
            vis[xx][yy]=1;
            q.push({xx,yy});
        }
    }
}
void solve() {
    cin >> n >> m >> a >> b;
    while(a--){
        int x,y;
        cin >> x >> y;
        q.push({x,y});
        G[x][y]=0;
        vis[x][y]=1;
    }
    bfs();
    while(b--){
        int x,y;
        cin >> x  >> y;
        cout << G[x][y] << endl;
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