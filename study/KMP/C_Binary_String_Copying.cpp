#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD1 = 1000000007;
const ll MOD2 = 1000000009;
const ll BASE = 911382323;

struct Hash {
    vector<ll> power;
    vector<ll> pref;
    vector<ll> ones;

    Hash() {}

    Hash(const string& s, ll mod) {
        int n = (int)s.size() - 1;

        power.assign(n + 1, 1);
        pref.assign(n + 1, 0);
        ones.assign(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            power[i] = power[i - 1] * BASE % mod;

            int value = s[i] - '0';

            // 原字符串前缀哈希
            pref[i] = (pref[i - 1] * BASE + value) % mod;

            // 长度为 i 的全 1 字符串的哈希
            ones[i] = (ones[i - 1] * BASE + 1) % mod;
        }
    }

    // 获取原字符串区间 [l, r] 的哈希
    ll getHash(int l, int r, ll mod) const {
        if (l > r) {
            return 0;
        }

        return (pref[r] -
                pref[l - 1] * power[r - l + 1] % mod +
                mod) % mod;
    }

    // 获取排序后完整字符串的哈希
    ll getResultHash(
        int L,
        int R,
        int n,
        int zeroCount,
        ll mod
    ) const {
        // 左边部分：原字符串 [1, L - 1]
        ll leftHash = getHash(1, L - 1, mod);

        // 中间排序后变成：
        // 000...000111...111
        // 前面的 0 没有贡献，后面的 1 有贡献
        int oneCount = R - L + 1 - zeroCount;
        ll middleHash = ones[oneCount];

        // 拼接左边和中间
        ll result = (
            leftHash * power[R - L + 1] +
            middleHash
        ) % mod;

        // 右边部分：原字符串 [R + 1, n]
        ll rightHash = getHash(R + 1, n, mod);

        // 拼接右边
        result = (
            result * power[n - R] +
            rightHash
        ) % mod;

        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        string s;
        cin >> s;
        s = " " + s;  // 改成 1 下标

        /*
            nxt1[i]：
            从 i 开始向右，第一个 1 的位置。
            如果不存在，设为 n + 1。
        */
        vector<int> nxt1(n + 2, n + 1);

        for (int i = n; i >= 1; i--) {
            if (s[i] == '1') {
                nxt1[i] = i;
            } else {
                nxt1[i] = nxt1[i + 1];
            }
        }

        /*
            pre0[i]：
            从 i 开始向左，第一个 0 的位置。
            也就是 [1, i] 中最右边的 0。
            如果不存在，设为 0。
        */
        vector<int> pre0(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') {
                pre0[i] = i;
            } else {
                pre0[i] = pre0[i - 1];
            }
        }

        Hash hash1(s, MOD1);
        Hash hash2(s, MOD2);

        set<pair<ll, ll>> resultSet;

        while (m--) {
            int l, r;
            cin >> l >> r;

            int L = nxt1[l];
            int R = pre0[r];

            /*
                L < R：
                区间中存在 "1 ... 0"，排序会改变字符串。

                L >= R：
                区间本来已经有序，排序后还是原字符串。
            */
            if (L >= R) {
                ll h1 = hash1.pref[n];
                ll h2 = hash2.pref[n];

                resultSet.insert({h1, h2});
                continue;
            }

            int zeroCount =
                hash1.prefZero.empty()
                    ? 0
                    : 0;

            // 统计原字符串 [L, R] 中 0 的数量
            // 这里不能使用 hash1.prefZero，因此单独预处理
            // 实际数量由 zeroPrefix 数组提供
        }

        cout << resultSet.size() << '\n';
    }

    return 0;
}
