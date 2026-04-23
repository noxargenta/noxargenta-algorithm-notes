#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    string s[8];
    for (int i=0; i<8; i++){
        cin >> s[i];
        for (int j=0;j<8;j++){
            if (s[i][j]=='*'){
                char c='a'+j;
                cout << c << 8-i;
            }
        }
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