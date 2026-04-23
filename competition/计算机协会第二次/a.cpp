#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int x;
    cin >> x;
    int x2=x/4;
    x=x%4;
    x=x/2;
    cout << x + x2 << "\n";
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