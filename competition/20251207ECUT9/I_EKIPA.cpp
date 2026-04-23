#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<double> mx(n+1);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int id;
            double x;
            cin >> id >> x;
            mx[id]=max(mx[id],x);
        }
    }
    sort(mx.begin()+1,mx.end());
    double ans=0;
    for(int i=n;i>n-k;i--){
        ans+=mx[i];
    }
    cout << fixed << setprecision(1) << ans << endl;
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