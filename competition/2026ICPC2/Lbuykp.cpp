#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n+1,0);
    vector<ll> prea(n+1,0),preb(n+1,0);
    for( ll i=1;i<=n;i++){
        cin >> a[i];
        prea[i]=a[i]+prea[i-1];
    }
    if(n==1){
        cout << a[1] << endl;
        return;
    }
    for(ll i=1;i<=n;i++){
        if(i==1){
            preb[i]=a[i];
        }else {
            preb[i]=a[n+2-i]+preb[i];
        }
    }   
    for(ll i=1;i<=n-1;i++){
        ll rig=
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