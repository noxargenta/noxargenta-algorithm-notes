#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int INF = INT_MAX;

ll f(ll a, ll b) {
    ll cnt = 1;
    while (a > cnt * (b + 1)) {
        cnt++;
    }
    return cnt;
}

void solve() {
    ll k, x1, y1, x2, y2;
    cin >> k >> x1 >> y1 >> x2 >> y2;
    ll a = x2 - x1;
    ll b = y2 - y1;
    if (b == 0) {
        cout << a << ' ' << a << endl;
    } else {
        cout << f(a, b) << ' ';
        if (y2 < k || x2 < k) {
            cout << a << endl;
        } else {
            if (x1 < k) {
                if (y2 >= x2) {
                    cout << max(k - x1, min(x2 - k + 1, (ll)2)) << endl;
                } else {
                    cout << max(k - x1, min(x2 - k + 1, (ll)3)) << endl;
                }
            } else {
                if (y2 >= x2) {
                    cout << min(a, min((ll)2, y2 - x1 + 1)) << endl;
                } else {
                    cout << min(a, min((ll)3, y2 - x1 + 2)) << endl;
                }
            }
        }
    }
}

signed main() {
    //  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll _ = 1;
    cin >> _;

    while (_--) {
        solve();
    }
    return 0;
}