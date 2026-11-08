#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n+1);
    vector<ll> b(n+1);
    k%=2;
    ll cnt0=0,cnt1=0,m0=0,m1=0,cnt=0;
    for(ll i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]%2 == !k){
            cnt++;
        }else if(a[i]&1){
            cnt1++;
        }else {
            cnt0++;
        }
    }
    for(ll i=1;i<=n;i++){
        cin >> b[i];
        if(b[i]&1){
            m1++;
        }else {
            m0++;
        }
    }

    if(cnt1>m1 || cnt0 > m0){
        cout << "NO\n";
    }else {
        cout << "YES\n";
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