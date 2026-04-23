#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int t;
    cin >> t;
    int a[t],b[t];
    for (int i=0;i<t;i++){
        cin >> a[i] >> b[i];
        if (a[i]>b[i]){
            int tem=b[i];
            b[i]=a[i];
            a[i]=tem;
        }
    }
    for (int i=0;i<t;i++){
        for (;a[i]>=1 && b[i]>=2;a[i]--,b[i]=b[i]-2){
        }
        if (b[i]==0 && a[i]==0){
            cout << "YES\n";
        }else {
            a[i]=a[i]-2;
            b[i]--;
            if (a[i]==0 && b[i]==0){
                cout << "YES\n";
            }else {
                cout << "NO\n";
            }
        }

    }
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