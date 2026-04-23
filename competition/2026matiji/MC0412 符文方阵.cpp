#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m;
    cin >> n >> m;
    int a[n][m][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int c=0;c<m;c++){
                cin >>a[i][j][c];
            }
        }
    }
    int b[m][m];
    for(int i=1;i<n;i++){
        for(int x=0;x<m;x++){
            for(int y=0;y<m;y++){
                int ans=0;
                for(int k=0;k<=m-1;k++){
                    ans+=a[0][x][k]*a[i][k][y];
                }   
                b[x][y]=ans%2;  
            }
        }
        for(int x=0; x<m; x++)
            for(int y=0; y<m; y++)
                a[0][x][y] = b[x][y];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout << a[0][i][j] << " ";
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