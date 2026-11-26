#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define ll long long
#define ull unsigned long long
void solve() {
    ll n;
    cin >> n;
    string s = "+--";
    ll a = 0, b = 0;
    for(ll i = 0; i < n; i++) {
        s += "+--";
    }
    cout << s << endl;
    ll x;
    cin >> x;
    
    b=x/3;
    if(x%3>=1){
        b++;
    }
    a = max(0LL, n - b);
    cout << a * 1 + b * 2 << endl;
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
/* < 2
< 2
> +-
< 0
> 2
< 3
> +-
< 1
> 5 */