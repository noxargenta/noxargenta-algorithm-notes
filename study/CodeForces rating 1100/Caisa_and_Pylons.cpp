#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    ll maxx=0;
    ll fir;
    for(ll i=0;i<n;i++){
        
        ll x;
        cin >> x;
        if(i==0)fir=x;
        maxx=max(x,maxx);
    }
    cout << maxx <<endl;
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