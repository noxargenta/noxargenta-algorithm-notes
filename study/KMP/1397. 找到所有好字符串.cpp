#include <bits/stdc++.h>
using namespace std;

const int MOD = 1'000'000'007;

class Solution {
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        int m = evil.size();

        // pi[i]：evil[0..i] 的最长真前后缀长度
        vector<int> pi(m, 0);
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && evil[i] != evil[j])
                j = pi[j - 1];
            if (evil[i] == evil[j])
                j++;
            pi[i] = j;
        }

        // go[j][c]：当前匹配长度为 j，添加字符 c 后的新匹配长度
        vector<vector<int>> go(m, vector<int>(26));
        for (int j = 0; j < m; j++) {
            for (int c = 0; c < 26; c++) {
                char ch = 'a' + c;
                int k = j;

                while (k > 0 && evil[k] != ch)
                    k = pi[k - 1];
                if (evil[k] == ch)
                    k++;

                go[j][c] = k;
            }
        }

        auto countUpTo = [&](const string& bound) {
            // dp[匹配长度][是否仍与 bound 前缀相等]
            vector<array<int, 2>> dp(m), ndp(m);
            dp[0][1] = 1;

            for (int i = 0; i < n; i++) {
                for (auto& row : ndp)
                    row = {0, 0};

                for (int j = 0; j < m; j++) {
                    for (int tight = 0; tight <= 1; tight++) {
                        int ways = dp[j][tight];
                        if (ways == 0) continue;

                        int limit = tight ? bound[i] - 'a' : 25;

                        for (int c = 0; c <= limit; c++) {
                            int nj = go[j][c];

                            // 完整匹配 evil，非法字符串不加入 DP
                            if (nj == m) continue;

                            int ntight = tight && (c == limit);
                            // tight 时 limit == bound[i]-'a'；
                            // 不 tight 时原本已经小于 bound，仍保持不 tight。
                            if (!tight)
                                ntight = 0;

                            ndp[nj][ntight] += ways;
                            if (ndp[nj][ntight] >= MOD)
                                ndp[nj][ntight] -= MOD;
                        }
                    }
                }
                dp.swap(ndp);
            }

            int result = 0;
            for (int j = 0; j < m; j++)
                result = (result + dp[j][0] + dp[j][1]) % MOD;
            return result;
        };

        auto containsEvil = [&](const string& text) {
            return text.find(evil) != string::npos;
        };

        int ans = countUpTo(s2) - countUpTo(s1);
        if (ans < 0) ans += MOD;

        if (!containsEvil(s1)) {
            ans++;
            if (ans == MOD) ans = 0;
        }

        return ans;
    }
};
