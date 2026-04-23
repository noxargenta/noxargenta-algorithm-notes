#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
     int n;
    cin >> n;

    for (int i = n; i <= 999; ++i) {
        int hundreds = i / 100;
        int tens = (i / 10) % 10;
        int units = i % 10;

        if (hundreds * tens == units) {
            cout << i << endl;
            return;
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