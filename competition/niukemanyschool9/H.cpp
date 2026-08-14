#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=1e18;
struct Node{
    ll step,x;
};
struct cmp{
    bool operator()(Node i,Node j){
        if(i.step==j.step) return i.x<j.x;
        return i.step<j.step;
    }
};
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,m;
    cin>>n>>m;
    vector<ll> edge[n+2],o_pos(n+2),o_time(n+2),dist(n+2,inf);
    dist[1]=0;
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    priority_queue<Node,vector<Node>,cmp> pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto [d,u]=pq.top();
        pq.pop();
        for(ll v:edge[u]){
            if(dist[v]==inf){
                dist[v]=d+1;
                pq.push({d+1,v});
            }
        }
    }
    vector<ll> final_time(m+2,0);
    for(ll i=0;i<m;i++){
        ll p,t;cin>>p>>t;
        final_time[i]=t+dist[p];
    }
    for(ll i=0;i<m;i++){
        cout<<final_time[i]<<" ";
    }
    cout<<endl;
    return 0;
}