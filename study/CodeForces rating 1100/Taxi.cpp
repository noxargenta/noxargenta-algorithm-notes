#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    vector<ll> cnt(5,0);
    for(ll i=0;i<n;i++){
        ll x;
        cin >> x;
        cnt[x]++;
    }
    ll ans=0;
    for(ll i=1;i<=4;i++){
        ll val=cnt[i]*i;
        ans+=val/4;
        val%=4;
        cnt[i]=val;
    }
    ll val=min(cnt[1],cnt[3]);
    ans+=val;
    cnt[1]-=val;
    cnt[3]-=val;
    if(cnt[1]!=0){
        ans++;
    }
    if(cnt[3]!=0){
        ans++;
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