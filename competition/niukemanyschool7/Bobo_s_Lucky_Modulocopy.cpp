#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, ans = 0;
    cin >> n;
    for (int b = 1; b * b <= n; b++) {
        int T = b * (b + 1);
        int cnt = n / T;
        int add = cnt * b;
        int rem = n % T;
        if (rem >= b * b) {
            add += rem - b * b + 1;
        }
        ans += add;
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