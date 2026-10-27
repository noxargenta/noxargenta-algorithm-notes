#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    ll ans=0;
    for(ll i=0;i<n;i++){
        if(a[i]<=ans){
            ans++;
        }else {
            ans--;
        }
    }
    cout << ans << " ";
    sort(a.begin(),a.end(),greater());
    ans=0;
    for(ll i=0;i<n;i++){
        if(a[i]<=ans){
            ans++;
        }else {
            ans--;
        }
    }
    cout << ans << endl;
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