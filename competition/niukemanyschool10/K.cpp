#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
const ll INFLL=LLONG_MAX;
void solve() {
    ll n;
    cin >> n;
    ll N=n*3;
    vector<vector<ll>> a(N,vector<ll>(N,1));
    for(ll i=0;i<N;i++){
        for(ll j=0;j<N;j++){
            cin  >> a[i][j];
        }
    }
    vector<ll> dp(1LL << N,-INFLL);
    vector<ll> g(1LL << N);
    for(ll i=0;i<N;i++){
        for(ll j=i+1;j<N;j++){
            for(ll k=j+1;k<N;k++){
                ll cur=(1LL<<i) | (1LL << j) | (1LL << k);
                g[cur]=a[i][j] + a[i][k] + a[j][k];
            }
        }
    }
    dp[0]=0;
    vector<vector<ll>> b()
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