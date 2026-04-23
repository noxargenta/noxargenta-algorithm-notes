#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int a[3];
    for (int i=0; i<3; i++){
        cin >> a[i];
    }
    string x;
    cin >> x;
    int color;
    if (x == "Red") {
        color = 0;
    } else if (x == "Green") {
        color = 1;
    } else if (x == "Blue") {
        color = 2;
    }
    a[color]=0;
    sort(a,a+3);
    cout << a[1];
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