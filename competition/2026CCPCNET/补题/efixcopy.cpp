#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> a(4,vector<ll> (n+1));
    vector<vector<ll>> pos(4,vector<ll> (n+1));
    for(ll i=1;i<=3;i++){
        for(ll j=1;j<=n;j++){
            cin >> a[i][j];
            pos[i][a[i][j]]=j;
        }
    }
    vector<ll> ok(n+1,0);
    auto check=[&](ll x,ll y){
        ll mx=0;
        for(ll i=1;i<n;i++){
            mx=max(mx,pos[y][a[x][i]]);
            if(mx==i){
                ok[i]=1;
            }
        }
    };
    check(1,2);
    check(1,3);
    check(2,3);
    ll ans=1;
    for(ll i=1;i<=n;i++){
        ans+=ok[i];
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