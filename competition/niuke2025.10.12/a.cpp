#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int x;
    cin >>x;
    int a,b,c,d,e;
    a=x/10000;
    b=x/1000%10;
    c=x/100%10;
    d=x/10%10;
    e=x%10;
    int sum=a+b+c+d+e;
    cout << sum%9;
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