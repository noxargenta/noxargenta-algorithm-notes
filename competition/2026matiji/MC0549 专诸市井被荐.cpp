#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m;
    cin >> n >> m;
    int ans=0;
    int minx=1000000009;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        minx=min(minx,x);
    }
    int maxx=minx+n-1;
    for(int i=1;i<=m;i++){
        int l,r;
        cin >> l >> r;
        l=max(l,minx);
        r=min(r,maxx);
        if(l<=r){
            ans+=(n-(r-l+1));
            ans%=10007;    
        }else {
            ans+=n;
            ans%=10007;
        }
        //或者说最后使用n*m- Σ（rx-lx+1）；
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