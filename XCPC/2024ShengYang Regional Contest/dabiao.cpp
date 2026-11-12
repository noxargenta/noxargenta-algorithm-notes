#include <bits/stdc++.h>
using namespace std;

int n, m, N;
vector<int> a, b;
vector<bool> used;

// 已经选好了 a，递归选择 b。
// start 保证 b 严格递增，避免枚举同一组数的不同排列。
bool dfsB(int start) {
    if ((int)b.size() == m)
        return true;

    int need = m - (int)b.size();

    for (int y = start; y <= N - need; y++) {
        vector<int> added;
        bool ok = true;

        // 尝试加入一列，检查这一列产生的颜色。
        for (int x : a) {
            int color = x * y % N;

            if (used[color]) {
                ok = false;
                break;
            }

            used[color] = true;
            added.push_back(color);
        }

        if (ok) {
            b.push_back(y);

            if (dfsB(y + 1))
                return true;

            b.pop_back();
        }

        // 撤销这次尝试。
        for (int color : added)
            used[color] = false;
    }

    return false;
}

// 枚举严格递增的 a。
bool dfsA(int start) {
    if ((int)a.size() == n) {
        b.clear();
        fill(used.begin(), used.end(), false);
        return dfsB(0);
    }

    int need = n - (int)a.size();

    for (int x = start; x <= N - need; x++) {
        a.push_back(x);

        if (dfsA(x + 1))
            return true;

        a.pop_back();
    }

    return false;
}

int main() {
    const int LIMIT = 12; // 暴力范围，不要直接改到很大

    for (n = 1; n <= LIMIT; n++) {
        // 交换行列不影响是否有解，只枚举 n <= m。
        for (m = n; n * m <= LIMIT; m++) {
            N = n * m;

            a.clear();
            b.clear();
            used.assign(N, false);

            bool found = dfsA(0);

            cout << "n = " << n
                 << ", m = " << m
                 << ": " << (found ? "Yes" : "No")
                 << '\n';

            if (found) {
                cout << "a: ";
                for (int x : a) cout << x << ' ';
                cout << '\n';

                cout << "b: ";
                for (int y : b) cout << y << ' ';
                cout << '\n';

                cout << "table:\n";
                for (int x : a) {
                    for (int y : b)
                        cout << setw(3) << x * y % N;
                    cout << '\n';
                }
            }

            cout << "--------------------\n";
        }
    }
}