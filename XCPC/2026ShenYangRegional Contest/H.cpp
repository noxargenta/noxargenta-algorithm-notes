#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
ll n;
#define ull unsigned long long
ll mx=0,my=0;
ll dx[]={1,0,-1,0};
ll dy[]={0,1,0,-1};
void solve() {
    cin >> n;
    vector<string> g(n);
    for(ll i=0;i<n;i++){
        cin >> g[i];
    }
    vector<vector<ll>> vis(10,vector<ll>(10,0LL));//1表示可以涂色
    vector<pair<ll,ll>> point;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(g[i][j]!='.'){
                vis[i][j]=2;//2表示战车的位置;
                point.push_back({i,j});
            }
        }
    }
    queue<pair<ll,ll>> q;
    for(auto [x,y] : point){
        
        // 清空;
        while(!q.empty()){
            q.pop();
        }


        q.push({x,y});
        mx=max(mx,x);
        my=max(my,y);

        while(!q.empty()){
            auto [x1,y1] = q.front();
            q.pop();
            for(ll i=0;i<4;i++){
                ll xx=x1+dx[i];
                ll yy=y1+dy[i];
                if(xx > mx || yy > my || yy<0 || xx < 0)continue;
                if(vis[xx][yy]==1){
                    vis[xx][yy]=-1;
                    g[xx][yy]=g[x1][y1];
                    q.push({xx,yy});
                }
                
            }
            ll inix=x1;
            ll iniy=y1;
            
        }
        for (ll xx = x + 1; xx < n && vis[xx][y] != 2 && vis[xx][y]!=-1; xx++) {
            vis[xx][y] = 1;
        }
        for(ll xx=x-1;xx>=0 && vis[xx][y]!=2 && vis[xx][y]!=-1;xx--){
            vis[xx][y]=1;
        }
        for (ll yy = y + 1; yy < n && vis[x][yy] != 2 && vis[x][yy]!=-1; yy++) {
            vis[x][yy] = 1;
        }
        for(ll yy=y-1;yy>=0 && vis[x][yy]!=2 && vis[x][yy]!=-1;yy--){
            vis[x][yy]=1;
        }
        cout << "debug------------" <<endl;
        for(auto x : g){
            for(auto y: x){
                cout << y;
            }
            cout << endl;
        }
        cout << "debug------------" <<endl;

    }
    for(auto x : g){
        for(auto y: x){
            cout << y;
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
1332
4432
4442
2222