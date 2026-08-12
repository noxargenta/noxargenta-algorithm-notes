#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n,m;
    cin >> n  >> m;
    vector<ll> a(2*n,0);
    for( ll i=0;i<2*n;i++){
        cin >> a[i];
    }
    ll minans=0;
    ll maxans=0;
    for(ll i=0;i<2*n;i+=2){
        if(i==0)a[i]+=m;
        if(a[i]>a[0] && a[i+1]>a[0]){
            
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