#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++){
        cin >>a[i];
    }
    vector<ll> dp(n+2,0);
    for(ll i=n;i>=1;i--){
        if(i+a[i]<=n){
            dp[i]=dp[i+a[i]]+a[i];
        }else {
            dp[i]=a[i];
        }
        // if(i==1){
        //     cout << a[i] << " " << dp[i] <<endl;
        // }
    }
    ll maxx=0;
    for(ll i=1;i<=n;i++){
        maxx=max(maxx,dp[i]);
    }
    cout << maxx <<endl;
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