#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    string in;
    getline (cin, in);
    //cout << in;
    for (int i=1;i<=(int)in.length();i=i+4){
        cout << in[i];
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