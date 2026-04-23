#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int x;
    cin >> x;
    for(int i=1;i<=x;i++){
        if(i*(i+1)==x){
            cout << "YES\n";
            break;
        }
        if(i*(i+1)>x){
            cout << "NO\n";
            break;
        }
    }
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    //cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}