#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    int diff=max(max(a+b,a+c),max(d+b,d+c))-min(min(a+b,a+c),min(d+b,d+c));
    cout << max(n*(n-diff),(int)0);
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