#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int dp[10000007];
void solve() {
    int t,m;
    cin >> t >> m;
    while(m--){
        int w,v;
        cin  >> w >> v;
        for(int i=w;i<=t;i++){
            dp[i] = max(dp[i],dp[i-w]+v);
        }
    }
    cout << dp[t] << endl;
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