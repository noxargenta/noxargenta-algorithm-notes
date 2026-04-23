#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int ans=1;
    int val=1;
    for(int i=1;i<n;i++){
        if(a[i]!=a[i+1]){
            val++;
            ans=max(ans,val);
        }else {
            val=1;
        }
    }
    cout << ans << endl;
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