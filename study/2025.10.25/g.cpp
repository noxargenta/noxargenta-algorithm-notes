#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf=0x7f7f7f7f;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1),pre(n+1),suf(n+2);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pre[i] =max(pre[i-1],a[i] + n-i);
    }
    for(int i=n;i>=1; i--){
        suf[i]=max(suf[i+1],a[i]+i-1);
    }
    int ans=inf;
    for(int i=1;i<=n;i++){
        ans=min(ans,max({a[i],pre[i-1],suf[i+1]}));
    }
    cout << ans << "\n";
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