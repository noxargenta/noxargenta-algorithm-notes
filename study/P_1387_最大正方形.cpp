#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n+1,vector<int> (m+1,0));
    vector<vector<int>> b(n+1,vector<int> (m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            b[i][j]=a[i][j];
            b[i][j]=b[i][j]+b[i-1][j]+b[i][j-1]-b[i-1][j-1];
        } 
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int len=1;i+len-1<=n && j+len-1<=m;len++){
                int x2=i+len-1;
                int y2=j+len-1;
                int x1=i;
                int y1=j;
                int sum=b[x2][y2]-b[i-1][y2]-b[x2][j-1]+b[i-1][j-1];
                if(sum==len*len){
                    ans=max(ans,len);
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