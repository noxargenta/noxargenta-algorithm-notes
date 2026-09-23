#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin  >> n;
    vector<ll> a(n);
    map<ll,ll> mp;
    ll mx=0;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        mp[a[i]]++;
        mx=max(mx,mp[a[i]]);
    }
    ll size=mp.size();
    ll ans;
    

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