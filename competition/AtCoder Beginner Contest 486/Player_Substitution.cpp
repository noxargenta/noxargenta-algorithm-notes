#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n+1);
    vector<ll> pos(1000);
    for(ll i=0;i<n;i++){
        cin >> a[i];
        pos[a[i]] = i;

    }
    vector<pair<ll,ll>> b(m+1);
    for(ll i=0;i<m;i++){
        ll x,y;
        cin >> x >> y;
        b[i].first = x;
        b[i].second = y;
        a[pos[x]] = y;
        pos[y] = pos[x];
        
    
    }
    sort(a.begin(),a.end()-1);
    for(ll i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;

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