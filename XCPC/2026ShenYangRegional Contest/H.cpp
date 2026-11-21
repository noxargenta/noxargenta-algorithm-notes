#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
ll n;
#define ull unsigned long long
ll l,r;

void solve() {
    cin >> n;
    vector<string> g(n);
    for(ll i=0;i<n;i++){
        cin >> g[i];
    }
    vector<vector<ll>> vis(10,vector<ll>(10,0LL));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(g[i][j]!='.'){
                vis[i][j]=2;//2表示战车的位置;
                
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