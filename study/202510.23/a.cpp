#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    i64 a,b;
    cin >> a >> b;
    if(a%b==0){
        cout  << a/b;
    }else {
        i64 sum=a/b;
        cout << sum +1;
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