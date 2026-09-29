#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
ll pos[100005];
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n+1,0);
    for(ll i=1;i<=n;i++){
        cin >> a[i];
        pos[a[i]]=i;
    }
    ll m;
    cin >> m;
    ll ans1=0,ans2=0;
    while(m--){
        ll x;
        cin >>x;
        ans1+=pos[x];
        ans2+=(n-pos[x]+1);
    }
    cout << ans1 << " " << ans2 <<endl; 
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