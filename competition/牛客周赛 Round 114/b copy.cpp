#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    int result =0;
    for (int l=0;l<n;l++) {
        int count1 = 0;
        int count2 = 0;
        int count3 = 0;
        for (int r = l; r < n; r++) {
            if (a[r] == '1') {
                count1++;
            } else if (a[r] == '2') {
                count2++;
            } else if (a[r] == '3') {
                count3++;
            }
            if (count1>0&&count1==count2&&count2==count3) {
                result++;
            }
        }
    }
    cout << result;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--) {
        solve();
    }
    return 0;
}