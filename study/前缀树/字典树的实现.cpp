#include <iostream>
#include <string>
using namespace std;

constexpr int MAXN = 100000 * 20 + 2;

// 根节点编号为 1，0 表示不存在
int head[MAXN];       // 第一个孩子
int nxt[MAXN];        // 下一个兄弟节点
char letter[MAXN];    // 当前节点对应的字符
int passCnt[MAXN];    // 经过当前节点的单词数量
int endCnt[MAXN];     // 以当前节点结尾的单词数量

int cnt = 1;

// 查找 u 的字符为 c 的孩子，最多检查 26 个节点
int findChild(int u, char c) {
    for (int v = head[u]; v != 0; v = nxt[v]) {
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

        if (v == 0) {
            v = ++cnt;
            letter[v] = c;

            // 将新节点插入孩子链表头部
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
        if (cur == 0) {
            return false;
        }
    }

    return endCnt[cur] > 0;
}

int prefixNumber(const string& pre) {
    int cur = 1;

    for (char c : pre) {
        cur = findChild(cur, c);
        if (cur == 0) {
            return 0;
        }
    }

    return passCnt[cur];
}

// delete 是 C++ 关键字，因此改名为 eraseWord
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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
            cout << (search(word) ? "YES" : "NO") << '\n';
        } else if (op == 4) {
            cout << prefixNumber(word) << '\n';
        }
    }

    return 0;
}#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}