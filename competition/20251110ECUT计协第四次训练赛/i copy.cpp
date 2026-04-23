#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int n;
    cin >> n;
    if(n & 1){
        n-=1;
        if(n/2 % 2==0){
            cout << n/2-1 << ' ' << n/2 + 1 << ' '<< 1 << endl;
        }else {
            cout << n/2 -2<< ' ' << n/2 +2 << ' '<< 1 << endl;
        }
    }else {
        cout << n/2 -1 << ' ' << n/2 << ' ' << 1 << endl;
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