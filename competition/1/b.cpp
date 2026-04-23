#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int x,k;
    cin >> x >> k ;
    int num=2;
    x=x-2*k;
    int temp=0;
    temp = (x/k)+1;
    num +=temp;
    cout << num;
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