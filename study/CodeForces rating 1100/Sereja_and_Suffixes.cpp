#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
ll n,m;
vector<ll> dp(1e5,0);
map<ll,bool> mp;
void solve() {
    cin >> n >> m;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    for(ll i=n;i>=1;i--){
        if(!mp[a[i]]){
            mp[a[i]]=1;
            dp[i]=dp[i+1]+1;
        }else {
            dp[i]=dp[i+1];
        }
    }

    while(m--){
        ll x;
        cin >> x;
        cout << dp[x] << endl;
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