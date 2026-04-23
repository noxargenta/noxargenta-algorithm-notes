#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
#define mod 998244353
void solve() {
    int a,n;
    cin >> a >> n;
    int ans=0,current=0;
    for(int i=1;i<=n;i++){
        current=(current*10+a)%mod;
        ans=(ans+current)%mod;
    }
    cout << ans ;
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