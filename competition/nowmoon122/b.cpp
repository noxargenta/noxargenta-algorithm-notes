#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n,k;
    cin >> n >> k;
    int n0=0,n1=0;
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        if (t==0){
            n0++;
        }else n1++;
    }
    if(n0>=k){
        cout << "0";
        return;
    }else if((k-n1)<((n+1)/2)){
        cout << "0";
        return;
    }else {
        cout << "1";
        return;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}