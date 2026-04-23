#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int a,b,c;
    cin >> a >> b >> c;
    int mx=max(max(a,b),c);
    int ms=min(min(a,b),c);
    if(mx-ms>=2){
        cout << "NO\n";
    }else {
        cout << "YES\n";
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