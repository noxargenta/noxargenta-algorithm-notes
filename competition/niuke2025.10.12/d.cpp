#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    i64 n=0;
    cin >>n;
    i64 sum=0;
    i64 mod=1000000007;
    for (i64 i=1;i<=n;i++){
        sum = (sum + (i % 5)) % mod;
    }
    i64 n2=1;
    for (i64 i=1;i<=n-1;i++){
        n2 = (n2 * i) % mod;
    }
    sum=(sum*n2)%mod;
    // cout << sum << endl;
    cout << sum;
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 _ = 1;
    // cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}