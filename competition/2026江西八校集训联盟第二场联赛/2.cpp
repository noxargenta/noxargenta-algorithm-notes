#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

// 仅将 string 改为 vector<ll>，避免数值转 char 溢出
vector<int> kmpMatch(const vector<ll>& string1, const vector<ll>& string2) {
    int n = string1.size();
    int m = string2.size();
    vector<int> match_pos(n, 0);
    if (m == 0) return match_pos;

    // 1. 构建 next 数组
    vector<int> nxt(m, 0);
    int j = 0;
    for (int i = 1; i < m; ++i) {
        while (j > 0 && string2[i] != string2[j]) j = nxt[j - 1];
        if (string2[i] == string2[j]) j++;
        nxt[i] = j;
    }

    // 2. 全局匹配一次，记录每个出现位置
    j = 0;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && string1[i] != string2[j]) j = nxt[j - 1];
        if (string1[i] == string2[j]) j++;

        if (j == m) {
            match_pos[i - m + 1] = 1; // 匹配成功的起始下标置 1
            j = nxt[j - 1];
        }
    }
    return match_pos;
}

void solve() {
    ll n, m, q;
    if (!(cin >> n >> m >> q)) return;

    vector<ll> a(n), b(m);
    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < m; i++) cin >> b[i];

    // 特判 m = 1
    if (m == 1) {
        while (q--) {
            ll l, r;
            cin >> l >> r;
            cout << (r - l + 1) << endl;
        }
        return;
    }

    vector<ll> prea, preb;
    for (ll i = 1; i < n; i++) prea.push_back(a[i] - a[i - 1]);
    for (ll i = 1; i < m; i++) preb.push_back(b[i] - b[i - 1]); // 原代码是 i<n，修正为 i<m

    // 在外面只跑一次 KMP
    vector<int> is_match = kmpMatch(prea, preb);

    // 做前缀和：pre_sum[i] 表示 prea 前 i 个位置中匹配成功的次数
    vector<int> pre_sum(prea.size() + 1, 0);
    for (int i = 0; i < (int)prea.size(); i++) {
        pre_sum[i + 1] = pre_sum[i] + is_match[i];
    }

    while (q--) {
        ll l, r;
        cin >> l >> r;
        if (r - l + 1 < m) {
            cout << 0 << endl;
            continue;
        }
        // 差分数组中，合法起点范围是 [l - 1, r - m]
        ll start_idx = l - 1;
        ll end_idx = r - m;
        cout << pre_sum[end_idx + 1] - pre_sum[start_idx] << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--) {
        solve();
    }
    return 0;
}