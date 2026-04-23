//11 22 33 44 55 66 77 88 99 110 121
//122 133 144
//1122 1133 1144;
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int x;
    cin >> x;
    int te=x%11;
    if(x>=te*111){
        cout << "YES\n";
    }else {
        cout << "NO\n";
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