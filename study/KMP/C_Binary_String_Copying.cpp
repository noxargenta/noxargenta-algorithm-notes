#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define ll long long
#define endl '\n'

const ll MOD1 = 1000000007;
const ll MOD2 = 1000000009;
const ll BASE = 911382323;

struct Hash {
    vector<ll> pw, pre, one;
    ll mod;

    Hash() {}

    Hash(string &s, ll mod) : mod(mod) {
        int n = (int)s.size() - 1;

        pw.assign(n + 1, 1);
        pre.assign(n + 1, 0);
        one.assign(n + 1, 0);

        for(int i=1;i<=n;i++) {
            pw[i] = pw[i - 1] * BASE % mod;

            int x = s[i] - '0';

            // 原字符串前缀哈希
            pre[i] = (pre[i - 1] * BASE + x) % mod;

            // 长度为 i 的全 1 字符串哈希
            one[i] = (one[i - 1] * BASE + 1) % mod;
        }
    }

    ll get(int l, int r) {
        if(l > r)return 0;

        ll res = pre[r] - pre[l - 1] * pw[r - l + 1] % mod;
        if(res < 0)res += mod;
        return res;
    }

    ll get_result(int L, int R, int cnt0, int n) {
        int len = R - L + 1;
        int cnt1 = len - cnt0;

        // 左边部分：原串 [1,L-1]
        ll left = get(1, L - 1);

        // 中间部分排序后为 000...111
        // 0 的贡献为 0，因此只需计算后面的 cnt1 个 1
        ll mid = one[cnt1];

        // 拼接左边和中间
        ll res = (left * pw[len] + mid) % mod;

        // 右边部分：原串 [R+1,n]
        ll right = get(R + 1, n);
 
        // 拼接右边
        res = (res * pw[n - R] + right) % mod;

        return res;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;
    s = " " + s;

    vector<int> nxt1(n + 2, n + 1);
    vector<int> pre0(n + 1, 0);
    vector<int> cnt0(n + 1, 0);

    // nxt1[i]：从 i 开始向右，第一个 1 的位置
    for(int i=n;i>=1;i--) {
        if(s[i] == '1')nxt1[i] = i;
        else nxt1[i] = nxt1[i + 1];
    }

    // pre0[i]：在 [1,i] 中，最右边的 0 的位置
    for(int i=1;i<=n;i++) {
        if(s[i] == '0')pre0[i] = i;
        else pre0[i] = pre0[i - 1];

        cnt0[i] = cnt0[i - 1] + (s[i] == '0');
    }

    Hash h1(s, MOD1);
    Hash h2(s, MOD2);

    set<pair<ll, ll>> st;

    while(m--) {
        int l, r;
        cin >> l >> r;

        int L = nxt1[l];
        int R = pre0[r];

        // 区间已经有序，排序后仍是原串
        if(L >= R) {
            st.insert({h1.pre[n], h2.pre[n]});
            continue;
        }

        // 统计有效区间 [L,R] 中 0 的个数
        int zero = cnt0[R] - cnt0[L - 1];

        ll x = h1.get_result(L, R, zero, n);
        ll y = h2.get_result(L, R, zero, n);

        st.insert({x, y});
    }

    cout << st.size() << endl;
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
