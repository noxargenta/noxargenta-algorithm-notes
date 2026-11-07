#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long

constexpr int MAXN = 100000 * 20 + 2;

int head[MAXN];     // 当前节点的第一个孩子
int nxt[MAXN];      // 当前节点的下一个兄弟
char letter[MAXN]; // 当前节点对应的字符
int passCnt[MAXN]; // 经过当前节点的单词数量
int endCnt[MAXN];  // 在当前节点结尾的单词数量

int cnt = 1;       // 根节点编号为 1

int findChild(int u, char c) {
    for (int v = head[u]; v!=0; v = nxt[v]) {
        if (letter[v] == c) {
            return v;
        }
    }
    return 0;
}

void insert(const string& word) {
    int cur = 1;
    ++passCnt[cur];

    for (char c : word) {
        int v = findChild(cur, c);
        if (!v) {
            v = ++cnt;
            letter[v] = c;
            nxt[v] = head[cur];
            head[cur] = v;
        }
        cur = v;
        ++passCnt[cur];
    }

    ++endCnt[cur];
}

bool search(const string& word) {
    int cur = 1;

    for (char c : word) {
        cur = findChild(cur, c);
        if (!cur) {
            return false;
        }
    }

    return endCnt[cur] > 0;
}

int prefixNumber(const string& pre) {
    int cur = 1;

    for (char c : pre) {
        cur = findChild(cur, c);
        if (!cur) {
            return 0;
        }
    }

    return passCnt[cur];
}

void eraseWord(const string& word) {
    if (!search(word)) {
        return;
    }

    int cur = 1;
    --passCnt[cur];

    for (char c : word) {
        cur = findChild(cur, c);
        --passCnt[cur];
    }

    --endCnt[cur];
}

void solve() {
    // 清空上一组数据，兼容多组测试
    // for (int i = 1; i <= cnt; ++i) {
    //     head[i] = nxt[i] = passCnt[i] = endCnt[i] = 0;
    //     letter[i] = 0;
    // }
    cnt = 1;

    int m;
    cin >> m;

    while (m--) {
        int op;
        string word;
        cin >> op >> word;

        if (op == 1) {
            insert(word);
        } else if (op == 2) {
            eraseWord(word);
        } else if (op == 3) {
            cout << (search(word) ? "YES" : "NO") << endl;
        } else if (op == 4) {
            cout << prefixNumber(word) << endl;
        }
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