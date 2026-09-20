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
    
    ll x=min(cnt[1],cnt[3]);
    cnt[4]+=x;
    cnt[3]-=x;
    cnt[1]-=x;
    cout << cnt[4] + cnt[3] + (cnt[1]*1 + cnt[2] * 2 + (4-1))/4 <<endl;
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