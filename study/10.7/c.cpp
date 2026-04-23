#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    i64 b;
    cin >> b;
    for (i64 a=1; a<=15; a++){
        i64 p=1;
        for (i64 i=0;i<a;i++){
            p*=a;
        }
    if (p == b){
        cout << a;
        return;
        }
    }   
    cout << -1;
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