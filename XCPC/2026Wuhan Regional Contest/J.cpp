#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long

void solve() {
    int n;
    cin >> n;

    map<int, int> cntA, cntB;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cntA[x]++;
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cntB[x]++;
    }

    vector<pair<int, int>> a;
    for (auto [v, c] : cntB) {
        a.push_back({v, c});
    }

    sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
        return x.first - x.second < y.first - y.second;
    });

    int k = 0;
    for (auto [v, c] : a) {
        if (k + c >= v) {
            k += c;
        } else if (cntA[v] < c) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

signed main() {
    // freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }

    return 0;
}