#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 9;
char s[MAXN];

int id(char c) { return c - 'a'; }

struct Trie {
    int cnt;
    int nxt[MAXN][26];
    Trie() { cnt = 0; memset(nxt, 0, sizeof(nxt)); }
    int insert(const char *s) {
        int p = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] == '#') break;
            int c = id(s[i]);
            if (!nxt[p][c]) nxt[p][c] = ++cnt;
            p = nxt[p][c];
        }
        return p;
    }
} T1, T2; // T1: 正序, T2: 逆序

struct BIT {
    int n;
    vector<int> bit;
    BIT(int n = MAXN) : n(n), bit(n + 1, 0) {}
    void add(int x, int v) {
        while (x <= n) {
            bit[x] += v;
            x += x & -x;
        }
    }
    int query(int x) {
        int ans = 0;
        while (x) {
            ans += bit[x];
            x -= x & -x;
        }
        return ans;
    }
} T3, T4;

vector<int> G[MAXN]; // 正序节点 -> 逆序节点
int dfn;
int be[MAXN], en[MAXN];

void dfs1(int u) { // 对逆序 Trie 求 DFS 序
    be[u] = ++dfn;
    for (int i = 0; i < 26; i++) {
        if (T2.nxt[u][i]) dfs1(T2.nxt[u][i]);
    }
    en[u] = dfn;
}

ll ans = 0;

void dfs2(int u) { // 遍历正序 Trie
    for (int v : G[u]) {
        // 统计祖先中的字符串（当前后缀是别人的后缀）
        ans += T3.query(be[v]);
        T3.add(be[v], 1);
        T3.add(en[v] + 1, -1);
        // 统计子树中的字符串（别人的后缀是当前后缀）
        ans += T4.query(en[v]) - T4.query(be[v]);
        T4.add(be[v], 1);
    }
    for (int i = 0; i < 26; i++) {
        if (T1.nxt[u][i]) dfs2(T1.nxt[u][i]);
    }
    // 回溯，撤销当前节点的贡献
    for (int v : G[u]) {
        T3.add(be[v], -1);
        T3.add(en[v] + 1, 1);
        T4.add(be[v], -1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        int x1 = T1.insert(s);
        int len = strlen(s);
        reverse(s, s + len); // 反转后插入逆序 Trie
        int x2 = T2.insert(s);
        G[x1].push_back(x2);
    }

    dfs1(0); // 对逆序 Trie 求 DFS 序
    dfs2(0); // 遍历正序 Trie 并统计答案
    printf("%lld\n", ans);

    return 0;
}