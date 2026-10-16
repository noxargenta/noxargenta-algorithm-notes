#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
ll g[2005],f[2005];//f是包含i在内的所有可能的种数f[x]表示背包大小是x所有n个物体混合配合达到的
//配合种数    g[x]是除去i之后的种数
void solve() {
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    f[0]=1;
    for(ll i=1;i<=n;i++){
        for(ll j=m;j>=a[i];j--){
            f[j]=(f[j]+f[j-a[i]])%10;
        }
    }
    for(ll i=1;i<=n;i++){
        g[0]=1;
        for(ll j=1;j<=m;j++){
            if(j<a[i])g[j]=f[j];
            else {
                g[j]=(f[j] - g[j-a[i]] + 10) % 10;
                
            }
            cout << g[j];
        }
        cout << endl;
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