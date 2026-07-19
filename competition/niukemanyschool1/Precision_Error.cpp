#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    int m=2*n;
    cout << m << endl;
    double d=0.010001;
    for(int i=0;i<n;i++){
        double x=(i%10)*d;
        double y=(i/10)*d;
        cout << fixed << setprecision(9) << x << " " << y <<" "<<   0.0 << endl;
    }
    for(int i=0;i<n;i++){
        double x=(i%10)*d;
        double y=(i/10)*d;
        cout << fixed << setprecision(9) << x << " " << y << " " << 1.0 << endl;
    }
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