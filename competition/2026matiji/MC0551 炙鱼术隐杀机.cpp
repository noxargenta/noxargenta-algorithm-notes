#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int n,m;
int a[1005][1005];
int b[1005][1005];
int s[1005][1005];
const int MOD = 1e9 + 7;
void solve() {
    cin >> n >> m;
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >>a[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            cin >> b[i][j];
        }
    }
    for(int p=0;p<30;p++){
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int bits_a=(a[i][j]>>p)&1;
                s[i][j]=bits_a + s[i-1][j] + s[i][j-1] -s[i-1][j-1];
            }
        }
        int bits_b_one=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                int k=i+n-m;
                int l=j+n-m;
                int ones_ina=s[k][l]-s[i-1][l]-s[k][j-1]+s[i-1][j-1];
                int bits_b=(b[i][j]>>p)&1;
                if(bits_b==1){
                    bits_b_one+=(n-m+1)*(n-m+1)-ones_ina;
                }else {
                    bits_b_one+=ones_ina;
                }
            }
        }
        int bitb=(1LL<<p)%MOD;
        ans=(ans+bitb*(bits_b_one%MOD))%MOD;    
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