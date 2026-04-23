#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    string s;
    cin >> s;
            if(s[0]!= 'Y' && s[0]!= 'y'){
                cout << "NO\n";
                return;
            }
            if(s[1]!= 'E' && s[1]!= 'e'){
                cout << "NO\n";
                return;
            }
            if(s[2]!= 'S' && s[2]!= 's'){
                cout << "NO\n";
                return;
            }
    cout << "YES\n";
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