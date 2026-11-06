#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n,k;
    cin >>n >> k;
    
    ll val=1;
    ll ans=0;
    for(ll i=1;i<=n;i*=2){
        ll cnt=min(k,n/i);
        ans+=cnt;
        n-=cnt*i;
    }
    cout << ans << endl;
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