#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(3,0);
    for(ll i=0;i<n;i++){
        for(ll j=0;j<3;j++){
            ll x;
            cin >>x;
            a[j]+=x;
        }
    }
    bool ok=1;
    for( ll i=0;i<3;i++){
        if(a[i]!=0){
            ok=0;
        }
    }
    if(ok){
        cout << "YES\n";
    }else {
        cout << "NO\n";
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