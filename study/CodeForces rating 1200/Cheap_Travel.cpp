#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n,m,a,b;
    cin  >> n >> m >> a >> b;
    if(b*1 >= m*a) {
        cout << n *a <<endl;
    }else {
        ll ans=(n/m )* b;
        //cout << "ans:" << ans <<endl;
        n%=m;
        ans+=(n*a);
        cout << ans <<endl;
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