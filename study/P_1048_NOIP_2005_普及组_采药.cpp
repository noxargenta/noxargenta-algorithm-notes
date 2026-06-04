#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int T,M;
int dp[105][1005];
int w[500],v[500];
void solve() {
    cin >> T >> M;
    //T为背包容量大小
    for(int i=1;i<=M;i++){
        cin >> w[i] >> v[i];
    }
    for(int i=0;i<=M;i++){
        for(int j=0;j<=T;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
                continue;
            }else {
                if(j>=w[i]){
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
                }else {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    cout << dp[M][T] << endl;
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