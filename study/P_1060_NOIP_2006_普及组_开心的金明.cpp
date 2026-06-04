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