#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;

auto qpow (ll x,ll k){
    ll ans=1;
    x%=mod;
    while(k>0){
        if(k & 1){
            ans= ans * x % mod;
        }
        x=x * x % mod;
        k >>= 1;

    }
    return ans;
}
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end(),greater<ll>());
    ll ans=1;

    for(ll i=0;i<n;i++){
        if(i!=n-2 && a[i] == a[i+1]){
            break;
        }
        ans = (ans + qpow(a[i]-1,i + 1)) % mod;
    }
    cout << ans << endl;
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