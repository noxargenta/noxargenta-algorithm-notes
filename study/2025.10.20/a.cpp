#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    vector<int> a(8);
    cin >> a[0];
    if(a[0]<100 || a[0]>675){
        cout << "No";
        return;
    }
    if(a[0]%25!=0){
        cout << "No";
        return;
    }
    for(int i=1;i<8;i++){
        cin >> a[i];
        if(a[i]<a[i-1]){
            cout << "No";
            return;
        }
        if(a[i]<100 || a[i]>675){
            cout << "No";
            return;
        }
        if(a[i]%25!=0){
            cout << "No";
            return;
        }
    }
    cout << "Yes";
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