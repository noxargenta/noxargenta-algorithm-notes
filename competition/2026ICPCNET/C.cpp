#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> g(n+1);
    vector<ll> deg(n+1,0);
    while(m--){
        ll l,r;
        cin >> l >> r;
        ll k=r-l+1;
        ll pre;
        cin >> pre;
        for(ll i=1;i<k;i++){
            ll cur;
            cin >> cur;
            g[pre].push_back(cur);
            deg[cur]++;
            pre= cur;
        }
    }
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    for(ll i=1;i<=n;i++){
        if(deg[i]==0){
            pq.push(i);
        }
    }
    vector<ll> ord;
    ord.push_back(-1);
    while(!pq.empty()){
        ll x=pq.top();
        pq.pop();
        ord.push_back(x);
        for(auto v : g[x]){
            deg[v]--;
            if(deg[v]==0){
                pq.push(v);
            }
        }
    }
    if((ll)ord.size()-1 < n){
        cout << -1 <<endl;
        return;
    }
    vector<ll> ans(n+1,0);
    for(ll i=1;i<=n;i++){
        ans[ord[i]]=i;
    }
    for(ll i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
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
//https://qoj.ac/contest/4071/problem/20018