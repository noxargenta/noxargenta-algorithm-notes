#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
const ll mod= 998244353;
void solve() {
    ll n;
    cin >> n;

    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++){
        cin  >> a[i];
    }
    ll b[n+1][n+1];
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            if(i== j){
                cout << (a[i] + 1)%mod<< " ";
            }else {
                cout << a[i] % mod << " ";
            }
        }
        cout << endl;
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