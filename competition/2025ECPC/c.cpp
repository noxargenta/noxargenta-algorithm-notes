#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    if(n==1){
        cout << 1 << endl;
        return ;
    }
    int count = 0;
    for (int i = 2; i<= n; ++i) {
        while (n % i == 0) {
            count++;
            n /= i;
        }
    }
    if (n > 1) {
        count++;
    }
    cout << count << endl;
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
