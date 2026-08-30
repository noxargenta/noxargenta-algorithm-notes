#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> b2;
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    for( ll i=0;i<n;i++){
        cin >> b[i];
        if(i==0 || b[i]!=b[i-1]){
            b2.push_back(b[i]);
        }
    }
    ll r=0;
    for(ll l=0;l<b2.size();l++){
        ll x=
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