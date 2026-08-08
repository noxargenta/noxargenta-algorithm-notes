#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    for(int b = 1; b <= 20; b++) {
        cout << "b = " << b << ": ";
            for(int a = 1; a <= 200; a++) {
                if((a % b) + 1 == a % (b + 1)) {
                    cout << a << " ";
                }
            }
        cout << endl;
    }
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 100;
    //cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}