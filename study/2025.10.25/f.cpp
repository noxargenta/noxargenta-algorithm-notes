#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >> n;
    vector<i64> a(n+1);
    vector<int> s(n+999);
    int vis[7]={0,-1,-1,-1,-1,-1,-1};
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i]+=a[i-1];
        s[i]=a[i]%7;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(vis[s[i]]!=-1){
            ans=max(ans,i-vis[s[i]]);
        }else {
            vis[s[i]]=i;
        }
    }
    cout << ans ;
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