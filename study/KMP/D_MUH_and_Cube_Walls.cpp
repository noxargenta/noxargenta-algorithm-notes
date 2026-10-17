#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n+1,0);
    vector<ll> b(m+1,0);
    
    vector<ll> difa(n+1,0);
    vector<ll> difb(n+1,0);
    for(ll i=1;i<=n;i++){
        cin >> a[i];
        difa[i]=a[i]-a[i-1];
    }
    for(ll i=1;i<=m;i++){
        cin>> b[i];
        difb[i]=b[i]-b[i-1];
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