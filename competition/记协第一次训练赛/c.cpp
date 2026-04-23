#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(),a.end());
    if(a[0]==a[1]){
        cout << a[2] << endl;
    }else {
        cout << a[0] << endl;
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