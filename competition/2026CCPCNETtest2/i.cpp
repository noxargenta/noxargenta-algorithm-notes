#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define ll long long
void solve(ll x) {
    if(x==0){
        ll n,m;
        cin >> n >> m;
        vector<vector<ll>> G(n+1);
        ll a[m][2];
        for(ll i=0;i<m;i++){
            for(ll j=0;j<2;j++){
                cin >> a[i][j];
            }
        }
        cout << m <<endl;
        for(ll i=0;i<m;i++){
            for(ll j=0;j<2;j++){
                cout << a[i][j] << " " ;
            }
            cout << endl;
        }
        for(ll i=1;i<=3;i++){
            ll x;
            cin >> x;
            while(x--){
                ll u,v;
                cin >> u >> v;
                G[u].push_back(v);
                G[v].push_back(u);
            }
        }
        ll ans=0;
        vector<bool> vis(n+1,0);
        deque<ll> dq;
        for(ll i=1;i<=n;i++){
            if(vis[i])continue;
            dq.clear();
            ll cur=1;
            dq.push_back(i);
            while(!dq.empty()){
                
                ll c=dq.front();
                dq.pop_front();
                for(auto x : G[c]){
                    if(vis[x]==0){
                        cur++;
                        vis[x]=1;
                        dq.push_back(x);
                    }
                }   
            }
            ans=max(cur,ans);
        }
        cout << ans << endl;
    }else {
        ll n,m;
        cin >> n >> m;
        vector<vector<ll>> G(n+1);
        ll a[m][2];
        for(ll i=0;i<m;i++){
            for(ll j=0;j<2;j++){
                cin >> a[i][j];
            }
        }
        cout << m <<endl;
        for(ll i=0;i<m;i++){
            for(ll j=0;j<2;j++){
                cout << a[i][j];
            }
            cout << endl;
        }
        ll x;
        cin >> x;
        cout << x <<endl;
    }

}

signed main(int,char* st[]) {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    ll x=st[1][0]-'0';
    while(_--) {
        solve(x);
    }
    return 0;
}