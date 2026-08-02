#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    if(n%2==1){
        if(n%3==0){
            cout << n*(n/2-1) + n/3 << endl;
            return;
        }
        cout << n*(n/2)<<endl;
    }else if(n%2==0){
        if(n%3==0){
            cout << n*(n/2-2) + n/3 <<endl;
            return;
        }
        cout << n*(n/2-1) <<endl;
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