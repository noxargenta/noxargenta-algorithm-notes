#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n+1,vector<int>(m+1));
    int ans=0;
    vector<vector<int>> b(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >>a[i][j];
            b[i][j]=a[i][j]+b[i-1][j]+b[i][j-1]-b[i-1][j-1];
            
        }
    }
    ////四个for循环是重点
    for (int x1 = 1; x1 <= n; x1++) {
        for (int y1 = 1; y1 <= m; y1++) {
            for (int x2 = x1; x2 <= n; x2++) {
                for (int y2 = y1; y2 <= m; y2++) {
                    int ones = b[x2][y2] - b[x1 - 1][y2] - b[x2][y1 - 1] + b[x1 - 1][y1 - 1];
                    int total = (x2 - x1 + 1) * (y2 - y1 + 1);
                    if (2 * ones > total) {
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
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