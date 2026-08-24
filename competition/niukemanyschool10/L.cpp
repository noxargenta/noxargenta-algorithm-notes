#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll m,r,c;
    cin >> m >> r >> c;
    cout << fixed << setprecision(12);
    if(c<=m){
        cout << (double)1 <<endl;
        return;
    }
    ll k0=(c-m)/(m+r);
    ll k1=k0+1;
    double ans0=(double)(k0+1)*m/c;
    double ans1=(double)(k1+1)*m/(k1*(m+r)+m);
    double ans3=(double)(m)/c;
    cout << max(max(ans0,ans1),ans3) <<endl;
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