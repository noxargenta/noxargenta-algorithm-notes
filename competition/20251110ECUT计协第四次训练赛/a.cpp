#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int x;
    cin >> x;
    int a[3];
    for(int i=0;i<3;i++){
        cin >> a[i];
    }
    for(int i=0;i<3;i++){
        if(a[i]!=x){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n" ;
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