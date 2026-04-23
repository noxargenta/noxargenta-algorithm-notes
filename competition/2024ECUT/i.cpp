#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int n;
    cin >> n;
    string end=to_string(n-1);
    int n2=n-end.length();
    cout << "1";
    for(int i=1;i<=n2;i++){
        cout << '0';
    }
    int x=n-1;
    cout << end << endl;
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