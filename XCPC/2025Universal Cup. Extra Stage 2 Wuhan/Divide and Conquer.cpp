#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n,m;
    cin >> n >> m;
    map<pair<ll,ll>,ll> mp; 
    vector<pair<ll,ll>> a(m);
    for(ll i=0;i<m;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(),a.end(),[&](ll x,ll r){
        if(a[x].second!=a[r].second){
            return a[x].second<a[r].second;
        }else {
            return a[x].first<a[r].first;
        }
    });
    for(ll i=0;i<n;i++){

    }
    
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