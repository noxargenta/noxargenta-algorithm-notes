#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    int ajia=0;
    int ajian=0;
    for(int i=0;i<n;i++){
        if(a[i]>b[i]){
            ajian+=(a[i]-b[i]);
        }else if(a[i]< b[i]){
            ajia+=(b[i]-a[i]);
        }else {
            continue;
        }
    }
    cout << ajian +1 << endl;
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