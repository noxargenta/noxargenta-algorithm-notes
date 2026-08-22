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
    
    vector<vector<ll>> b(n+1);//n个队伍的状态数组
    for(ll i=0;i<(1LL << N);i++){
        ll cnt=__builtin_popcount(i);
        if(cnt%3==0){
            b[cnt/3].push_back(i);
        }
    }
    dp[0]=0;
    for(ll cnt=0;cnt<n;cnt++){
        for(auto mask : b[cnt]){
            if(dp[mask]==-INFLL)continue;
            vector<ll> tmp;
            for(ll i=0;i<N;i++){
                if(!((mask >> i) & 1)){
                    tmp.push_back(i);
                }
            }
            ll m=tmp.size();
            ll i=0;
            for(ll j=i+1;j<m;j++){
                for(ll k=j+1;k<m;k++){
                    ll cur=(1LL<<i) | (1LL << j) | (1LL << k);
                    dp[mask | cur]=max(dp[mask|cur],dp[mask] + g[cur]);
                }
            }
        }
    }
    cout << dp.back() <<endl;
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