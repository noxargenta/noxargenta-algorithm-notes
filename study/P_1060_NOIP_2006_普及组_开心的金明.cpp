#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int n,m;
void solve() {
    cin >> n >> m;
    int dp[m][n];
    int v[m+2],w[m+2];
    for(int i=1;i<=m;i++){
        cin >> v[i] >> w[i];
    }    
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }else {
                if(j>=v[i]){
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+v[i]*w[i]);
                }else {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    cout << dp[m][n] << endl;
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