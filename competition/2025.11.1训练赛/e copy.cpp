#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >> n;
    int ji=0,ou=0;
    vector<int> a(n);
    for(int i=0;i< n;i++){
        int t;
        cin >> t;
        a[i]=t;
        if(t%2==0){
            ou++;
        }else {
            ji++;
        }
    }
    if(ji==0 || ou == 0){
        for(int i=0;i< n;i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }else {
        sort(a.begin(),a.end());
        for(int i=0;i< n;i++){
            cout << a[i] << " ";
        }
        cout << endl;
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