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
    for(int i=0;i<M;i++){
        cin >> w[i] >> v[i];
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