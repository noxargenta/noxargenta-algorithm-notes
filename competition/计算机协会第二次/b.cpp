#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int x;
    cin >>x;
    if(x<=1399){
        cout << "Division 4" << "\n";
    }else if(x<=1599){
        cout << "Division 3" << "\n";
    }else if(x<=1899){
        cout << "Division 2" << "\n";
    }else if(x <= 1900){
        cout << "Division 1" << "\n";
    }else {
        cout << "Division 1" << "\n";
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