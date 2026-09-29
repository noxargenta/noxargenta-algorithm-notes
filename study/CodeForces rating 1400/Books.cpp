#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n,t;
    cin >> n >> t;
    vector<ll> a(n+1,0);
    
    vector<ll> pre(n+1,0);
    for(ll i=1;i<=n;i++){
        cin >> a[i];
        pre[i]=pre[i-1]+a[i];
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ll b=pre[i-1];
        ll need=pre[i-1]+t;
        ll idx=upper_bound(pre.begin(),pre.end(),need)-pre.begin();
        idx--;
        ans=max(ans,idx-i+1);
    }
    cout << ans <<endl;
    
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