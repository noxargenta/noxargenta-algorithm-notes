#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin  >> a[i];
    }
    cout << "-1\n";
    for(int i=2;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            if(a[j]>a[i]){
                cout << j << endl;
                break;
            }
            if(j==1 ){
                cout << "-1\n";
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