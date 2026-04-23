#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >>n;
    int sum=1;
    int x[n];
    for (int i=0;i<n;i++){
        cin >> x[i];
    }
    for (int i=0;i<n;i++){
        sum *= x[i];
    }
    int k=0;
    int sum2=-999;
    while (sum2 < sum) {
        sum2=1;
        k++;
        for (int i = 0 ; i<k;i++){
            sum2*=30;
        }
    }
    while (sum % sum2 != 0) {
        k--;
        sum2=1;
        for (int i=0; i< k;i++){
            sum2*=30;
        }
    }
    cout << k;
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