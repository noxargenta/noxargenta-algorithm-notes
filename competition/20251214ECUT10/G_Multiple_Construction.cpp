#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
   //string s="";
    for(int i=n-1;i>=1;i--){
        cout << i << ' ';
    }
    cout << n << ' ';
    for(int i=1;i<=n;i++){
        cout << i << ' ';
    }
    cout << endl;
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