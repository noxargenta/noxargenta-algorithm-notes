#include <bits/stdc++.h>
using namespace std;

int a[8], b[8], p[8];
double dp[8];

void dfs(int l, int r) {
    if (l == r) {
        dp[l] = 1;
        return;
    }

    int mid = (l + r) / 2;
    dfs(l, mid);
    dfs(mid + 1, r);

    double tmp[8] = {};

    for (int i = l; i <= mid; i++) {
        for (int j = mid + 1; j <= r; j++) {
            // i 的种子编号小，使用 a；j 使用 b
            double x = a[p[i]], y = b[p[j]];
            double meet = dp[i] * dp[j];

            tmp[i] += meet * x / (x + y);
            tmp[j] += meet * y / (x + y);
        }
    }

    for (int i = l; i <= r; i++) {
        dp[i] = tmp[i];
    }
}

int main() {
    for (int i = 0; i < 8; i++) {
        cin >> a[i] >> b[i];
        p[i] = i;
    }

    double ans = 0;
    do {
        dfs(0, 7);

        for (int i = 0; i < 8; i++) {
            if (p[i] == 0) {
                ans = max(ans, dp[i]);
            }
        }
    } while (next_permutation(p, p + 8));

    cout << fixed << setprecision(15) << ans << '\n';
}