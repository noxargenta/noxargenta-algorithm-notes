#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n, p;
    cin >> n >> p;

    vector<pair<ll, ll>> a(n);
    vector<ll> xs;
    xs.reserve(2 * n);

    for (ll i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        xs.push_back(a[i].first);
        xs.push_back(a[i].second);
    }

    // 排序、去重，完成坐标离散化
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    int m = (int)xs.size();
    vector<ll> dif(m + 2, 0);
    vector<ll> b(m + 2, 0);

    for (ll i = 0; i < n; i++) {
        // 下标从 1 开始
        int l = lower_bound(xs.begin(), xs.end(), a[i].first)
                - xs.begin() + 1;
        int r = lower_bound(xs.begin(), xs.end(), a[i].second)
                - xs.begin() + 1;

        // 保存离散化后的端点，最后统计时直接使用
        a[i] = {l, r};

        dif[l]++;
        dif[r + 1]--;
    }

    for (int i = 1; i <= m; i++) {
        b[i] = b[i - 1] + dif[i];
    }

    ll ans2 = 0;
    for (ll i = 0; i < n; i++) {
        if (abs(b[a[i].first] - b[a[i].second]) >= p) {
            ans2++;
        }
    }

    cout << ans2 << endl;
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