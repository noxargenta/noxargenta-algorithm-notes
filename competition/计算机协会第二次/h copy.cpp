#include <bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; ++i)
        {
            a[i][i] = 1;
        }
        for (int i = 1; i <= n; ++i)
        {
            a[i][n - i + 1] = 1;
        }
        if (n & 1)
        {
            a[1][(n + 1) / 2] = a[n][(n + 1) / 2] = a[(n + 1) / 2][1] = a[(n + 1) / 2][n] = 1;
            a[(n + 1) / 2][(n + 1) / 2] = 0;
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
