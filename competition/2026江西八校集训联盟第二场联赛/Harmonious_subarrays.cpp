#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int>a(n), b(m);
    vector<int>sa(n, 0), sb(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for (int i = 1; i < n; i++) {
        sa[i] = a[i] - a[i - 1];
    }

    for (int i = 1; i < m; i++) {
        sb[i] = b[i] - b[i - 1];
    }
    vector<int>pre(n + 2, 0);
    int im = n - m + 1;
    if (m == 1) {
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + 1;
        }
    } else {

        for (int i = 1; i <= im; i++) {
            bool ok = 1;
            int x = i;
            for (int j = 1; j <= m - 1 ; j++) {
                if (sa[x + j - 1] != sb[j]) {
                    ok = 0;
                    break;
                }
            }
            pre[i] = pre[i - 1] + ok;
        }
        for (int i = im; i <= n; i++) {
            pre[i] = pre[i - 1];
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int y = r - m + 1;
        y = min(y, im);
        if (l > y) {
            cout << 0 << endl;
        } else {
            int ans = pre[y] - pre[l - 1];
            cout << ans << endl;
        }
    }
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