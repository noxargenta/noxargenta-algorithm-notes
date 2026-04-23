#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    char x;
    cin >> x;
    string ch="codeforces";
    for(int i=0;i<10;i++){
        if(x==ch[i]){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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