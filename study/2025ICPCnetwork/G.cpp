#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n,m;
    cin >> n >> m;
    vector<bool> vis(n+1,0);
    if(m<n){
        cout << "No\n";
        return;
    }
    while(m--){
        ll x,y;
        cin >> x >> y;
        if(abs(x-y)==1){
            vis[min(x,y)]=1;
        }
    }
    for(ll i=1;i<n;i++){
        if(vis[i]!=1){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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