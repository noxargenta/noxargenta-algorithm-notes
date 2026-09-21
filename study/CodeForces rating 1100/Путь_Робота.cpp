#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
ll dx[]={1,0,-1,0};
ll dy[]={0,-1,0,1};
char dd[]={'R','D','L','U'};
void solve() {
    ll n,m;
    cin >> n >> m;
    vector<vector<bool>> vis(n,vector<bool>(m,0));
    vector<string> a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
        
    }
    auto dfs=[&](ll x,ll y){
        for(ll i=0;i<4;i++){
            ll x2=dx[i];
            ll y2=dy[i];
            if(x2>=0 && x2 <n && y2>=0 && y2 <m){
                if(!vis[x2][y2] && a[x2][y2]=='*'){
                    cout << dd[i];
                    self()
                }
            }
        }

    };
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