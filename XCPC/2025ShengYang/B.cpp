#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n,m;
    ll a,b;
    cin >>n >> m >> a >> b;
    ll k=n*m;
    map<ll,ll> cnt;
    for(ll i=0;i<k;i++){
        ll x;
        cin >> x;
        cnt[x]++;

    }
    vector<ll> f;
    for(ll i=1;i<=k;i++){
        if(cnt[i]!=0){
            f.push_back(cnt[i]);
        }
    }
    sort(f.begin(),f.end(),greater<ll>());
    ll cur=1LL*(k-cnt[0])*a;
    ll ans=cur;
    for(ll i=0;i<(ll)f.size();i++){
        ll t=max(0LL,a-1LL*i*b);
        
    }

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