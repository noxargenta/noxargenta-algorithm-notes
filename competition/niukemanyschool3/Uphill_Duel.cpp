#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
void solve() {
    int n,m;
    cin >> n >> m;
    //int g[n][m];
    vector<int> h(n*m);
    vector<int> idd(n*m);
    for(int i=0;i<n*m;i++){
        cin >> h[i];
        idd[i]=i;
    }
    sort(idd.begin(),idd.end(),[&](int a,int b){
        return h[a]>h[b];
    });
    vector<int> dp(n*m,0);//0 Second 1First
    for(int i=0;i<n*m;i++){
        int id=idd[i];
        int x=id/m;
        int y=id%m;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx >= n || nx<0 || ny >= m || ny < 0)continue;
            else {
                int idx=nx*m+ny;
                if(h[id]<h[idx] && dp[idx]==0){
                    dp[id]=1;
                    break;
                }
            }
        }
    }
    int q;
    cin >> q;
    while(q--){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        if(dp[x*m+y]==1){
            cout << "First\n";
        }else {
            cout << "Second\n";
        }
    }
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}