#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n+1);
    vector<ll> b(n+1);

    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    for(ll i=1;i<=n;i++){
        cin >> b[i];
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