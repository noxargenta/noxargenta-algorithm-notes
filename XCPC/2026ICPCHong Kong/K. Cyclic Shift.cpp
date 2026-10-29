#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n;
    cin >>  n;
    vector<ll> a(2*n+10);
    ll pos=-1;
    ll val=LLONG_MAX;
    for(ll i=1;i<=n;i++){
        cin >> a[i];
        a[i+n]=a[i];
        if(a[i]<val){
            val=a[i];
            pos=i;
        }
    }
    val=-1;
    for(ll i=pos;i<pos+n;i++){
        val=max(val,a[i]);
        cout << val <<  " " ;
    }
    cout << endl;
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