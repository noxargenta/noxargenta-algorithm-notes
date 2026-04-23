#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf=0x7f7f7f7f;
int a[105];
i64 qw[105][100005];
void solve() {
    int n,maxx=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        for(int j=1;j<=a[i];j++){
            int x;
            cin >> x;
            qw[i][x] ++;    
            maxx=max(maxx,x);
        }
    }
    double maxpos=0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            double pos=0;
            for(int k=1;k<=maxx;k++){
                pos+=((long double)qw[i][k]/a[i])*((long double)qw[j][k]/a[j]);
            }
            maxpos = max(maxpos,pos);
        }
    }
    printf("%.15lf",maxpos);
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