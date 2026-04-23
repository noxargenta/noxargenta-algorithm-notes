#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int fac(int n){
    int sum =1;
    for(int i=2;i<=n;i++){
        sum *= i;
    }
    return sum;
}

void solve() {
    int n,r;
    cin >> n >> r;
    vector<vector<int>> a(n+1,vector<int>(r+1));
    a[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=r;j++){
            a[i][j] = a[i-1][j] * j + a[i-1][j-1];
        }
    }
    cout << a[n][r]*fac(r);
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