#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    int sum;
    vector<int> a(n+1),pre(n+1),suf(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    pre[1]=a[1];
    int g=a[1];
    for(int i=2;i<=n;i++){
        g=__gcd(a[i],g);
        pre[i]=g;
    }
    suf[n]=a[n];
    g=a[n];
    for(int i=n-1;i>=1;i--){
        g=__gcd(a[i],g);
        suf[i]=g;
    }
    int ans=0;
    for(int i=2;i<=n-1;i++){
        ans+=min(pre[i],suf[i]);
    }
    cout << ans+g << endl;
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