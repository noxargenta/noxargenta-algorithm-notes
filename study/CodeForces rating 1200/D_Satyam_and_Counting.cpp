#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    bool g[2][n+1];
    memset(g,0,sizeof g);
    ll x[n],y[n];
    ll a=0,b=0;
    for(ll i=0;i<n;i++){
        cin >> x[i] >> y[i];
        if (y[i])
            a ++;
        else
            b ++;
        g[y[i]][x[i]]=1;
    }
    ll ans=0;
    for(ll i=0;i<=n;i++){
        if(g[1][i]==1 && g[0][i]==1){
            ans+=a+b-2;
        }
        //斜三角形
        for(ll j=0;j<2;j++){
            if(i>0 && i<n && g[j][i] && g[!j][i+1] && g[!j][i-1]){
                ans++;
            }
        }
        
    }
    cout << ans << endl;
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