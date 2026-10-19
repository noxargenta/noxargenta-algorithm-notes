#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n,p;
    cin >>n >> p;
    vector<pair<ll,ll>> a(n);
    vector<ll> dif(n+100);
    for(ll i=0;i<n;i++){
        cin >>a[i].first >> a[i].second;
        dif[a[i].first]++;
        dif[a[i].second+1]--;
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