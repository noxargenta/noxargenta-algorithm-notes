#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n,0);
    vector<ll> b(n-1,0);
    vector<ll> c(n-2,0);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    for(ll i=0;i<n-1;i++){
        cin >> b[i];
    }
    for(ll i=0;i<n-2;i++){
        cin >> c[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    for(ll i=0;i<n;i++){
        if(i==n-1){
            cout << a[i] <<endl;
            break;
        }
        if(a[i]!=b[i]){
            cout << a[i] <<endl;
            break;
        }
    }
    for(ll i=0;i<n-1;i++){
        if(i==n-2){
            cout << b[i] <<endl;
            break;
        }
        if(b[i]!=c[i]){
            cout << b[i] <<endl;
            break;
        }
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