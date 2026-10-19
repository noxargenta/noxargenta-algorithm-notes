#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n,p;
    cin >> n >> p;
    vector<pair<ll,ll>>a(n);
    vector<ll> xs;
    for(ll i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;
        xs.push_back(a[i].first);
        xs.push_back(a[i].second);
        
    }
    sort(xs.begin(),xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    ll m=xs.size();
    vector<ll> dif(m+10,0);
    vector<ll> b(m+100,0);
    for(ll i=0;i<n;i++){
        ll l=lower_bound(xs.begin(),xs.end(),a[i].first)-xs.begin()+1;
        ll r=lower_bound(xs.begin(),xs.end(),a[i].second)-xs.begin()+1;
        
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