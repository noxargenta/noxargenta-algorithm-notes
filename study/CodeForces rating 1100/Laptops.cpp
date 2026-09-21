#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    vector<pair<ll,ll>> a(n+1,0);
    for(ll i=1;i<=n;i++){
        cin >> a[i].first;
    }
    for(ll i=1;i<n;i++){
        cin >> a[i].second;

    }
    sort(a.begin()+1,a.end(),[&](pair<ll,ll> x ,pair<ll,ll> y){
        x.first<y.first;
    });
    ll maxx=0;
    for(ll i=1;i<n;i++){
        maxx=max(maxx,a[i].second);
        if(a[i].second<maxx){
            cout  << "Happy Alex\n";
            return;
        }
    }
    cout << "Poor Alex\n";  

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