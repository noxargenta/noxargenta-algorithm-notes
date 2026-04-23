#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n+1,vector<int> (n+1,-1));
    a[0][(n-1)/2]=1;
    int r=0,c=(n-1)/2,k=1;
    for(int i=0;i<n*n-1;i++){
        int nr=(r-1+n)%n;
        int nc=(c+1)%n;
        if(a[nr][nc]==-1){
            a[nr][nc]=k+1;
            r=nr,c=nc,k++;
        }else {
            a[((r+1+n)%n)][c]=k+1;
            r=((r+1+n)%n),k++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << a[i][j] << " ";
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