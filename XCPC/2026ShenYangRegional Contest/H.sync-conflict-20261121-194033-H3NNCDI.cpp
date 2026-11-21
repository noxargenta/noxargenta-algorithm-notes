#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> a(n);
    for (auto &s : a) {
        cin >> s;
    }

    vector<string> ans(n, string(n, '.'));
    vector<bool> used(n, false);

    // 按行从上到下处理每一辆车。
    for (int i = 0; i < n; ++i) {
        int p = -1;
        char color = '.';

        for (int j = 0; j < n; ++j) {
            if (a[i][j] != '.') {
                p = j;
                color = a[i][j];
                break;
            }
        }

        used[p] = true;

        // 找到包含 p 的最大连续已处理列区间。
        int L = p, R = p;
        while (L > 0 && used[L - 1]) {
            --L;
        }
        while (R + 1 < n && used[R + 1]) {
            ++R;
        }

        // 只填空格，不覆盖之前的颜色。
        for (int x = 0; x <= i; ++x) {
            for (int y = L; y <= R; ++y) {
                if (ans[x][y] == '.') {
                    ans[x][y] = color;
                }
            }
        }
    }

    for (const auto &s : ans) {
        cout << s << '\n';
    }

    return 0;
}
