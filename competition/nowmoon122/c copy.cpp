#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n,m;
    cin >>n >>m;
    vector<int> a(n);
    int fu=0,zheng=0,zero=0;
    for (int i=0;i<n;i++){
        cin >>a[i];
        if(a[i]>0){
            zheng++;
        }else if(a[i]<0){
            fu++;
        }else{
            zero++;
        }
    }
    if(m==zheng){
        cout << "0\n";
        return;
    }

    if (zheng > m) {
        int needed = zheng - m;
        if (fu + zero > 0) {
            cout << needed << "\n";
        } else {
            cout << "-1\n";
        }
    } else {
        int needed = m - zheng;
        if (fu >= needed + 1) {
            cout << needed << "\n";
        } else {
            cout << "-1\n";
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _ ;
    while(_--) {
        solve();
    }
    return 0;
}