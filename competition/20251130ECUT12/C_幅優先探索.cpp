#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
char tu[55][55];
int ans[55][55];
void solve() {
    int r,c;
    cin >> r >> c;
    int sy,sx;//default
    cin >> sx >> sy;
    int gy,gx;
    cin >> gx >> gy;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> tu[i][j];
        }
    }
    queue<int> q,p;
    tu[sx][sy]='#';
    q.push(sx);
    p.push(sy);
    ans[sx][sy]=0;
    while(q.size()){
        for(int i=0;i<4;i++){
            int x=q.front()+dx[i];
            int y=p.front()+dy[i];
            if(x>0&&x<=r&&y>0&&y<=c&&tu[x][y]=='.'){
                q.push(x);
                p.push(y);
                tu[x][y]='#';
                ans[x][y]=ans[q.front()][p.front()]+1;
            }
        }
        q.pop();
        p.pop();
    }
    cout << ans[gx][gy] << endl;
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    //cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}