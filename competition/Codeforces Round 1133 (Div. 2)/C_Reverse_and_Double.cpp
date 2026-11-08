#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), d(n), pre(n + 1), suf(n + 1);
    for(int& v : a) cin >> v;

    for(int i = 0; i < n - 1; i++)
        d[i] = abs(a[i] - a[i + 1]);

    for(int i = 0; i < n; i++)
        pre[i + 1] = max(pre[i], d[i]);

    for(int i = n - 1; i >= 0; i--)
        suf[i] = max(suf[i + 1], d[i]);

    auto check = [&](int x) {
        int p = 0;
        while(p < n - 1 && d[p] <= x) p++;
        if(p == n - 1) return true;

        auto ok = [&](int l, int r, int mx) {
            return 2 * mx <= x && pre[max(0, l - 1)] <= x && suf[r + 1] <= x && (l == 0 || abs(a[l - 1] - 2 * a[r]) <= x) && (r == n - 1 || abs(2 * a[l] - a[r + 1]) <= x);
        };

        int mx = 0;
        for(int r = p + 1; r < n; r++) {
            if(r > p + 1) mx = max(mx, d[r - 1]);
            if(ok(p + 1, r, mx)) return true;
        }

        mx = 0;
        for(int l = p; l >= 0; l--) {
            if(l < p) mx = max(mx, d[l]);
            if(ok(l, p, mx)) return true;
        }

        return false;
    };

    int l = 0, r = pre[n];
    while(l < r) {
        int mid = (l + r) / 2;
        if(check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    cout << l << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
}