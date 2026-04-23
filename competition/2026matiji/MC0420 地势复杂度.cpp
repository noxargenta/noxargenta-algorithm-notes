#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> b(n+1,vector<int> (m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int val;
            cin >> val;
            b[i][j]+=val + b[i-1][j]+b[i][j-1] - b[i-1][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << b[i][j]/(i*j) << ' ' ;
        }
        cout << endl;
    }

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