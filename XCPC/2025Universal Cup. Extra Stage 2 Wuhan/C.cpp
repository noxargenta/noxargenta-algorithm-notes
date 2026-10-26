#include <bits/stdc++.h>
using namespace std;

using Grid = vector<string>;

const string P[3] = {
    "011220",
    "102102",
    "220011"
};

Grid transpose(const Grid& a) {
    int n = (int)a.size();
    int m = (int)a[0].size();

    Grid b(m, string(n, '0'));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            b[j][i] = a[i][j];
        }
    }

    return b;
}

// n 是 3 的倍数。
// 使用条件：n == 3，或者 m >= 5。
Grid build3(int n, int m) {
    Grid a(n, string(m, '0'));

    for (int i = 0; i < n; ++i) {
        int block = i / 3;
        int row = i % 3;

        // 奇数编号条带上下翻转。
        if (block % 2 == 1) {
            row = 2 - row;
        }

        for (int j = 0; j < m; ++j) {
            a[i][j] = P[row][j % 6];
        }
    }

    return a;
}

// 构造 4 × m，其中 m >= 6 且 m 是 3 的倍数。
Grid build4(int m) {
    Grid a = build3(3, m);
    a.push_back(a[2]);

    if (m % 6 == 3) {
        string patch = "220101120";

        for (int j = 0; j < 9; ++j) {
            a[3][m - 9 + j] = patch[j];
        }
    }

    return a;
}

// 这里保证 n, m >= 3。
Grid construct(int n, int m) {
    // 让行数成为 3 的倍数。
    if (n % 3 != 0) {
        return transpose(construct(m, n));
    }

    // 转置后只剩三行。
    if (m == 3 && n > 3) {
        return transpose(build3(3, n));
    }

    // 边长为 4 的特殊构造。
    if (m == 4 && n > 3) {
        return transpose(build4(n));
    }

    // 此时 n == 3，或者 m >= 5。
    return build3(n, m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        Grid ans;

        if (min(n, m) <= 2) {
            int d = min(n, m);
            int len = max(n, m);

            if (len > 6) {
                cout << "No\n";
                continue;
            }

            Grid a(d, string(len, '0'));

            for (int i = 0; i < d; ++i) {
                for (int j = 0; j < len; ++j) {
                    a[i][j] = char('0' + j / (len / 3));
                }
            }

            ans = (n == d ? a : transpose(a));
        } else {
            ans = construct(n, m);
        }

        cout << "Yes\n";
        for (const string& row : ans) {
            cout << row << '\n';
        }
    }

    return 0;
}