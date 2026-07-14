#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m;
    cin >>n >> m;
    vector<int> a(n+1);
    vector<bool> b(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=m;i++){
        int x;
        cin >> x;
        b[x]=1;
    }
    vector<vector<int>> dp(n+2,vector<int>(2,0));
    dp[n+1][0]=0;
    dp[n+1][1]=-1000000009;
    for(int i=n;i>=1;i--){
        if(b[i]==1){
            dp[i][0]=max(dp[i+1][0],dp[i+1][1]) + a[i];
            dp[i][1]=max(dp[i+1][0],dp[i+1][1]) - a[i];
        }else {
            dp[i][0]=dp[i+1][0] + a[i];
            dp[i][1]=dp[i+1][1] - a[i];
        }
    }
    cout << max(dp[1][0],dp[1][1]) << endl;
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