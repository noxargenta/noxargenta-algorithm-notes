#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int x;
    cin >> x;
    string s=to_string(x);
    cout << 1;
    string ans((s.length()-1),'0');
    cout << ans;
    cout << 1 << endl;
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