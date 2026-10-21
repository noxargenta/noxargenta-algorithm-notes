#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long

class Solution {
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        const ll MOD = 1000000007;
        string pat = evil;
        int m = pat.length();

        // ===== 1. 预处理 next：与你原来的写法相同 =====
        vector<int> nxt(m + 1);
        int i = 0, j = -1;
        nxt[0] = -1;

        while (i < m) {
            while (j != -1 && pat[i] != pat[j]) {
                j = nxt[j];
            }
            nxt[++i] = ++j;
        }

        // ===== 2. KMP 自动机 =====
        // go[j][c]：匹配长度为 j，追加字符 c 后的新匹配长度
        vector<vector<int>> go(m, vector<int>(26));

        for (int i = 0; i < m; i++) {
            for (int c = 0; c < 26; c++) {
                char ch = char('a' + c);
                int k;

                if (pat[i] == ch) {
                    k = i + 1;
                } else if (i == 0) {
                    k = 0;
                } else {
                    k = go[nxt[i]][c];
                }

                go[i][c] = k;
            }
        }

        // ===== 3. 记忆化搜索 =====
        // f[i][j][low][high]，-1 表示还没计算
        // 放在 class Solution 中、函数外，作为成员变量
        ll f[505][55][2][2];
        memset(f,-1,sizeof f);
        
        auto dfs = [&](auto &&self, int i, int j,
                       int low, int high) -> ll {
            // 能进入这个状态，说明之前一直没有出现 evil
            // 所有位置已经填完，得到一种合法方案
            if (i == n) return 1;

            ll &ans = f[i][j][low][high];
            if (ans != -1) return ans;
            ans = 0;

            int l = low ? s1[i] - 'a' : 0;
            int r = high ? s2[i] - 'a' : 25;

            for (int c = l; c <= r; c++) {
                int nj = go[j][c];

                // 出现完整 evil：直接丢弃，不能回退后继续
                if (nj == m) continue;

                // 原来贴着边界，且当前字符等于边界字符，
                // 下一位才继续受对应边界限制
                int nlow = low && (c == s1[i] - 'a');
                int nhigh = high && (c == s2[i] - 'a');

                ans += self(self, i + 1, nj, nlow, nhigh);
                ans %= MOD;
            }

            return ans;
        };

        // 初始为空串，同时与上下界的空前缀相等
        return dfs(dfs, 0, 0, 1, 1);
    }
};
