#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
const int N=200;
int G[N][N];
int dp[N][N];
int dx[]={2,1,-1,-2,-2,-1,1,2};
int dy[]={1,2,2,1,-1,-2,-2,-1};
bool block[N][N];
bool check(int x,int y){
    if(x<0 || y<0)return 0;
    return 1;
}
void solve() {
    int n,m;
    int x,y;
    cin >> n >> m >> x >> y;
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         dp[i][j]=1;
    //     }
    // }
    block[x][y]=1;
    dp[x][y]=0;
    for(int i=0;i<8;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(check(xx,yy)){
            block[xx][yy]=1;
        }
    }
    dp[0][0]=1;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(block[i][j]){
                dp[i][j]=0;
                continue;
            }else{
                if (i > 0) dp[i][j] += dp[i-1][j];
                if (j > 0) dp[i][j] += dp[i][j-1];
            }
        }
    }
    cout << dp[n][m] << endl;
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