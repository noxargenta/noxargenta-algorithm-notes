#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long

const int mod = 1e9 + 7;

int qpow(int a, int b) {
    int res = 1;
    a %= mod;
    while(b > 0) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    
    int m = 0;
    vector<pair<int, int>> cnt;
    
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x == -1) {
            m++;
        } else {
            if(cnt.empty() || cnt.back().first != x) {
                cnt.push_back({x, 1});
            } else {
                cnt.back().second++;
            }
        }
    }

    int even = 1;
    for(auto p : cnt) {
        even = even * qpow(2, p.second - 1) % mod;
    }

    int k = 0;
    for(int i = 1; i < cnt.size(); i++) {
        if(cnt[i].first == cnt[i - 1].first + 1) {
            k++;
        }
    }

    if(m == 0) {
        cout << even << endl;
    } else {
        int ans = qpow(2, m - 1);
        ans = ans * even % mod;
        ans = ans * (1 + k) % mod;
        cout << ans << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}