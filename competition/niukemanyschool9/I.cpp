#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int x, a, b;
    cin >> x >> a >> b;
    int ans = (x + b - 1) / b;
    int maxk = 2e5;
    for (int k = 1; k <= maxk; k++) {
        int c = a * k * (k + 1) / 2 - k * (k - 1) / 2;
        if (c >= x) {
            ans = min(ans, k);
            break;
        }
        int r = x - c;
        int add = 0;
        int du = k * (a - 1);
        while (r > 0 && du > 0) {
            add++;
            int m = b + du;
            r -= m;
            du--;
        }
        if (r > 0) {
            add += (r + b - 1) / b;
        }
        ans = min(ans, k + add);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}