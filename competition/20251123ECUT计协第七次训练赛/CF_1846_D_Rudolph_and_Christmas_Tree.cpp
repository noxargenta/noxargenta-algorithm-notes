#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    i64 n;
    double d,h,x;
    cin >> n >> d >> h;
    double last=0;
    double ans=d*h/2*n;
    for(int i=1;i<=n;i++){
        cin >> x;
        if(last>x){
            ans-=d*(last-x)*(last-x)/(2*h);
        }
        last=x+h;
    }
    cout << fixed << setprecision(8) << ans << endl;
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}