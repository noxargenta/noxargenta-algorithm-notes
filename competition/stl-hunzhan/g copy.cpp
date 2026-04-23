#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n=0;
    cin >> n;
    string a[3][n];
    for (int i=0;i<n;i++) {
        cin >>a[0][i];
        a[2][i]=a[0][i];
    }

    string temp;
    cin >> temp;
    for (int i=0;i<n;i++) {
        a[1][i]=temp[i];
    }

    for (int i=0;i<n;i++) {
        string t_n=a[0][i];
        string t_c=a[1][i];
        for (int j=0;j<n;j++) {
            if (a[2][j]==t_n) {
                if (a[1][j]!= t_c) {
                    cout <<"NO\n";
                    return;
                }
            }
        }
    }

    cout << "YES\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}