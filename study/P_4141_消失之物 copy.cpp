#include <iostream>
using namespace std;

const int N = 2005;
int n, m, w[N], f[N], g[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> w[i];

    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= w[i]; j--)
            f[j] = (f[j] + f[j - w[i]]) % 10;

    for (int i = 1; i <= n; i++) {
        g[0] = 1;
        for (int j = 1; j <= m; j++) {
            if (j < w[i]) g[j] = f[j];
            else          g[j] = (f[j] - g[j - w[i]] + 10) % 10;
            cout << g[j];
        }
        cout << '\n';
    }
    return 0;
}
