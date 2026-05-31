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
void bfs(){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
    }
}
void solve() {
    cin >> n >> m >> a >> b;
    while(a--){
        int x,y;
        cin >> x >> y;
        q.push({x,y});
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