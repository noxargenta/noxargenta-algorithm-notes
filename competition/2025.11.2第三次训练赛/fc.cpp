#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        cin >> b[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]>=b[i]){
            a[i]-=b[i];
            b[i]=0;
        }else {
            b[i]-=a[i];
            a[i]=0;
        }
    }
    i64 ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]>a[i-1]){
            ans += a[i]-a[i-1];
        }
        if(b[i]>b[i-1]){
            ans +=b[i]-b[i-1];
        }
    }
    cout << ans << endl; 
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    //cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}