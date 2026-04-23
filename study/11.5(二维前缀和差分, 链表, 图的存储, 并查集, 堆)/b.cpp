#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> diff(n+2,vector<int> (n+2,0));
    for(int i=0;i<m;i++){
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    diff[x1][y1]++;
    diff[x1][y2+1]--;
    diff[x2+1][y1]--;
    diff[x2+1][y2+1]++;
    }
    i64 total=0;
    vector<vector<int>> cov(n+2,vector<int> (n+2,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cov[i][j]=cov[i-1][j] + cov[i][j-1] -cov[i-1][j-1] + diff[i][j];
            total += (i64)(i+j) ^ cov[i][j];
        }
    }
    cout << total;
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