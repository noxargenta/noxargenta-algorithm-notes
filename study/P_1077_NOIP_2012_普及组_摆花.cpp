#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
const int N=105,mod=1e6+7;
int n,m;
int a[N],dp[N][N][N];
//1、第n种花  2、多少盆   3、所有数字的总和  =方案数
void solve() {
    cin >> n >> m;
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        for(int k=0;k<=m;k++){
            for(int j=0;j<=min(a[i],k);j++){
                if(j==0 && k==0)dp[i][j][k]=1;
                else {
                    for(int p=0;p<=min(a[i-1],k-j);p++){
                        dp[i][j][k] += dp[i-1][p][k-j];
                        dp[i][j][k] %= mod;
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=min(m,a[n]);i++){
        ans+=dp[n][i][m];
        ans %= mod;
    }
    cout<< ans <<  endl;
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