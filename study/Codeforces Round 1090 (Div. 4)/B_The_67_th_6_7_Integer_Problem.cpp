#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int a[7];
    int sum=0;
    int maxx=-9999;
    for(int i=0;i<7;i++){
        cin >> a[i];
        sum-=a[i];
        maxx=max(maxx,a[i]);
    }
    cout << sum + 2 * maxx << endl;

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