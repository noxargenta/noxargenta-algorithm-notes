#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n;
    cin >> n;

    vector<ll> a(n+1);

    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    ll ans=0;
    ll maxx=-1;
    ans+=max(a[n],a[1]);
    maxx=max(maxx,a[n]);
    for(ll i=1;i<n;i++){
        ans+=max(a[i],a[i+1]);
        maxx=max(maxx,a[i]);
    }
    cout << ans-maxx <<endl;
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