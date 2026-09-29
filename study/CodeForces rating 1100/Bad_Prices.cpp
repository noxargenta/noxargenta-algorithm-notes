#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    ll ans=0;
    ll minn=LLONG_MAX;
    for(ll i=n;i>=1;i--){
        if(a[i]>minn){
            ans++;
        }
        minn=min(a[i],minn);
    }   
    cout << ans <<endl;
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