#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int n,m,s[6000][6000];
void solve() {
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int x,y,v;
        cin >> x >> y >> v;
        s[x+1][y+1] +=v;
    }
    int F=5001;
    for(int i=1;i<=F;i++){
        for(int j=1;j<=F;j++){
            s[i][j] = s[i-1][j] +s[i][j-1] -s[i-1][j-1] +s[i][j];
        }
    }
    int sum=0;
    for(int i=m;i<=F;i++){
        for(int j=m;j<=F;j++){
            int num=s[i][j]-s[i-m][j] -s[i][j-m] +s[i-m][j-m];
            sum = max(num,sum);
        }
    }
    cout << sum;
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