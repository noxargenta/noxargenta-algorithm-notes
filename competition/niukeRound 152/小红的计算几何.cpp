#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    double k;
    cin >> k;
    double a,b,c,d;
    cin >> a   >> b  >> c >> d;
    double S=k*k;
    double xx=fabs(a-c);
    double yy=fabs(b-d);
    cout << fixed << setprecision(5);
    cout << S+k*yy +k*xx << endl;
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