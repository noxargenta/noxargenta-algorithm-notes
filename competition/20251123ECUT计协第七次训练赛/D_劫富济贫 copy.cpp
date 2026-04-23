#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
 int n; cin >> n;
 vector<int> v(n);
 int sum = 0;
 for(int i = 0; i < n; ++ i) {
 cin >> v[i];
 sum += v[i];
 }
 if(n /= 2) {
 cout << -1 << "\n";
 return;
 }
 sort(v.begin(), v.end());
 
 int idx = n / 2;
 int price = v[idx] * 2 * n - sum + 1;
 if(price < 0) cout << 0 << '\n';
 else cout << price << "\n";
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