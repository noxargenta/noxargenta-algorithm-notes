#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF=1e18;
using pll=pair<ll,ll>;
using ppll=pair<pll,pll>;//allweight  weight x y;
struct Node{
    ll val;
    ll y,x;
};
ll dx[2]={1,0};
ll dy[2]={0,1};
void solve(){
    ll n;
    cin >> n;
    ll a[n];
    //ll g[n][n];
    for(ll i=0;i<n;i++){
        cin >> a[i];
        //g[i][0]=a[i];
    }
    // for(ll j=1;j<n;j++){
    //     for(ll i=0;i<n;i++){
    //         if(i==0){
    //             g[i][j]=g[n-1][j-1];
    //         }else {
    //             g[i][j]=g[i-1][j-1];
    //         }
    //     }
    // }
    //debug
    // for(ll j=0;j<n;j++){
    //     for(ll i=0;i<n;i++){
    //         cout << g[j][i] << " ";
    //     }
    //     cout << endl;
    // }

    vector<vector<ll>> dist(n,vector<ll>(n,INF));
    priority_queue<ppll,vector<ppll>,greater<>> pq;
    pq.emplace(a[0],0,0);
    while(!pq.empty()){
        auto u=pq.top();
        pq.pop();
        for(ll i=0;i<2;i++){
            ll nx=u.second.first+dx[i];
            ll ny=u.second.second+dy[i];
            if(dist[ny][nx]>u.first.first+a[b([u.first.second]-(i==0?1:(-1)))%n]){
                dist[ny][nx]=u.first.first+a[b([u.first.second]-(i==0?1:(-1)))%n];
                pq.emplace(dist[ny][nx],ny,nx);
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll _=1;
    cin >> _;
    while(_--){
        solve();
    }
}-+