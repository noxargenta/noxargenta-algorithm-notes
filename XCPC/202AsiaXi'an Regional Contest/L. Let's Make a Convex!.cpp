#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a.begin()+1,a.end(),greater<ll>());
    vector<ll> s(n + 1, 0), ans(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }

    ll l = 1;
    for (ll k = n; k >= 3; k--) {
        while (l + k - 1 <= n) {
            ll sum = s[l + k - 1] - s[l - 1];

            // 降序排列，a[l] 就是当前最长边
            if (sum - a[l] > a[l]) {
                ans[k] = sum;
                break;
            }

            // 当前最长边不行，换短一点的最长边
            l++;
        }
    }

    for (ll k = 1; k <= n; k++) {
        cout << ans[k] << (k == n ? '\n' : ' ');
    }
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