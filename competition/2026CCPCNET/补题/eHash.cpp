#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
mt19937_64 rng(time(0));
void solve() {
    ll n;
    cin >> n;
    ll b[n+1];
    unsigned ll prehash[4]={};
    vector<vector<ll>> a(4,vector<ll> (n+1,0));
    for(ll i=1;i<=3;i++){
        for(ll j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    for(ll i=1;i<=n;i++){
        b[i]=rng();
    }
    ll ans=1;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=3;j++){
            prehash[j] ^= b[a[j][i]];
        }
        if(prehash[1]==prehash[2] || 
        prehash[2]==prehash[3]||
        prehash[1]==prehash[3]){
            ans++;

        }
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