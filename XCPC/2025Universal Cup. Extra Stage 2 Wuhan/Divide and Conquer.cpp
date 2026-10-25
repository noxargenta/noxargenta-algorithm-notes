#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n,m;
    cin >> n >> m;
    map<pair<ll,ll>,ll> mp; 
    vector<pair<ll,ll>> a(m);
    for(ll i=0;i<m;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(),a.end(),[&](auto  x,auto  r){
        if(x.second!=r.second){
            return x.second<r.second;
        }else {
            return x.first<r.first;
        }
    });
    ll cnt=0;
    ll x=-1;
    for(ll i=0;i<m;i++){
        ll l=a[i].first;
        ll r=a[i].second;
        
        if(x>=l && x <= r){
            continue;
        }else {
            x=r;
            cnt++;
        }
        mp[a[i]]++;
    }
    for(ll i=1;i<64;i++){
        if((1 << i)-1 >= cnt){
            cout << i << endl;
            return;
        }
    }
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