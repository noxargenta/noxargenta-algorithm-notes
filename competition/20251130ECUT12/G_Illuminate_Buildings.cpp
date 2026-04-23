#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<n+1;i++){
        cin >> a[i];
    }
    int dp[3005][3005];
    int ans=-0x7f7f7f7f;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=1;
            if(i-j>=1 && a[i-j]==a[i]){
                dp[i][j]=dp[i-j][j]+1;
            }
            ans=max(ans,dp[i][j]);
        }

    }
    cout << ans << endl;
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