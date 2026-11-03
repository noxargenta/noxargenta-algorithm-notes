#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    map<ll,ll> cnta,cntb;
    for(ll i=1;i<=n;i++){
        cin >> a[i];
        cnta[a[i]]++;
    }
    for(ll i=1;i<=n;i++){
        cin >> b[i];
        cntb[b[i]]++;
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