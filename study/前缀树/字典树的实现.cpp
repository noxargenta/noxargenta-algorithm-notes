#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long

// 最多 m 次插入，每次最多新增 20 个节点
constexpr int MAXN = 100000 * 20 + 2;

int tree[MAXN][26];
int endCnt[MAXN];
int passCnt[MAXN];
int cnt;

void build() {
    cnt = 1;
}

void insert(const string& word) {
    int cur = 1;
    ++passCnt[cur];

    for (int i = 0; i < (int)word.size(); ++i) {
        int path = word[i] - 'a';

        if (tree[cur][path] == 0) {
            tree[cur][path] = ++cnt;
        }

        cur = tree[cur][path];
        ++passCnt[cur];
    }

    ++endCnt[cur];
}

int search(const string& word) {
    int cur = 1;

    for (int i = 0; i < (int)word.size(); ++i) {
        int path = word[i] - 'a';

        if (tree[cur][path] == 0) {
            return 0;
        }

        cur = tree[cur][path];
    }

    return endCnt[cur];
}

int prefixNumber(const string& pre) {
    int cur = 1;

    for (int i = 0; i < (int)pre.size(); ++i) {
        int path = pre[i] - 'a';

        if (tree[cur][path] == 0) {
            return 0;
        }

        cur = tree[cur][path];
    }

    return passCnt[cur];
}

void deleteWord(const string& word) {
    if (search(word) > 0) {
        int cur = 1;
        --passCnt[cur];

        for (int i = 0; i < (int)word.size(); ++i) {
            int path = word[i] - 'a';

            if (--passCnt[tree[cur][path]] == 0) {
                tree[cur][path] = 0;
                return;
            }

            cur = tree[cur][path];
        }

        --endCnt[cur];
    }
}

void clear() {
    for (int i = 1; i <= cnt; ++i) {
        fill(tree[i], tree[i] + 26, 0);
        endCnt[i] = 0;
        passCnt[i] = 0;
    }
}

void solve() {
    int m;

    // 和原 Java 一样，支持读取到文件结束
    while (cin >> m) {
        build();

        for (int i = 1; i <= m; ++i) {
            int op;
            string word;
            cin >> op >> word;

            if (op == 1) {
                insert(word);
            } else if (op == 2) {
                deleteWord(word);
            } else if (op == 3) {
                cout << (search(word) > 0 ? "YES" : "NO") << endl;
            } else if (op == 4) {
                cout << prefixNumber(word) << endl;
            }
        }

        clear();
    }
}

signed main() {
    // freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }

    return 0;
}