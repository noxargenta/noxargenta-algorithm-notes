#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int g, h, i, j, k, l;
    cin >> g >> h >> i >> j >> k >> l;
    int x_min = max(a, g);
    int x_max = min(d, j);
    bool x_overlaps = (x_min < x_max);
    int y_min = max(b, h);
    int y_max = min(e, k);
    bool y_overlaps = (y_min < y_max);
    int z_min = max(c, i);
    int z_max = min(f, l);
    bool z_overlaps = (z_min < z_max);
    if (x_overlaps && y_overlaps && z_overlaps) {
        cout << "Yes";
    } else {
        cout << "No";
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