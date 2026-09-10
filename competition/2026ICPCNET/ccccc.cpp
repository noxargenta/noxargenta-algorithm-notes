#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n,m;cin>>n>>m;
    vector<ll> edge[n+1];
    vector<ll> in_degree(n+1,0);
    for(ll i=0;i<m;i++){
        ll l,r;
        cin>>l>>r;
        vector<ll> t(r-l+1);
        for(ll j=0;j<=r-l+1;j++){
            cin>>t[j];    
        }
        for(ll j=0;j<r-l;i++){
            ll u=t[j];
            ll v=t[j+1];
            edge[u].push_back(v);
            in_degree[v]++;
        }
    }
    priority_queue<ll> pq;
    for(ll i=1;i<=n;i++){
        if(in_degree[i]==0) pq.push(i);
    }
    vector<ll> q;
    
    while(!pq.empty()){
        ll u=pq.top();pq.pop();q;.push_back(u);
        for(ll v:edge[u]){
            in_degree[v]--;
            if(in_degree[v]==0){
                pq.push(v);
            }
        }
    }
    ll len=q.size();
    if(len!=n){
        cout<<-1<<endl;
        return;
    }
    vector<ll> ans(n+1,0);
    for(ll i=0;i<len;i++){
        ans[q[i]]=(i+1);
    }
    for(ll i=1;i<=n;i++){
        cout<<ans[i]<<((i!=n)?" ":"");
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}