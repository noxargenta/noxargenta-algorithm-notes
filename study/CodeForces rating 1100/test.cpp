#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    for(ll i=1;i<=100000;i++){
        if((double)((i-3+1)*180*1.0/i)-(i-3+1)*180*1.0/i < 0.1);
        cout << (double)((i-3+1)*180*1.0/i) <<endl;
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