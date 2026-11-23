#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf=4e18;

void solve() {
    ll n,m,a,b,c;
    cin>>n>>m>>a>>b>>c;
    vector<ll> d(n,0);
    for(ll i=0;i<n;i++) cin>>d[i];
    if(a<b){
        cout<<n*a<<endl;
        return;
    }
    vector<ll> vals=d;
    sort(vals.begin(),vals.end());
    vals.erase(unique(vals.begin(),vals.end()),vals.end());
    ll k=vals.size();
    for(ll & x:d){
        x=lower_bound(vals.begin(),vals.end(),x)-vals.begin()+1;
    }
    vector<ll> best(k+1,inf),add(k+1,0);
    vector<vector<ll>> dp(k+1,vector<ll>(k+1,inf));
    dp[0][0]=0;
    best[0]=0;
    ll miss=c-a,hit=b-a;
    for(ll x:d){
        add[x]+=hit;
        if(best[x]<inf) best[x]+=hit;
        // 讨论dp[u][x]
        for(ll u=0;u<=k;u++){
            if(u==x) continue;
            ll cand=inf;
            ll val_xu=dp[u][x];
            if(val_xu<inf) cand=min(cand,val_xu+add[u]+hit);
            if(best[u]<inf) cand=min(cand,best[u]+miss);
            if(cand<inf){
                best[x]=min(cand,best[x]);
                dp[x][u]=min(dp[x][u],cand-add[x]);
            }
        }
    }
    ll min1=*min_element(best.begin(),best.end());
    cout<<(a*n+min1)<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}