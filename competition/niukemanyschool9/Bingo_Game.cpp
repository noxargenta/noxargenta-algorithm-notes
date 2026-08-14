#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,m;cin>>n>>m;
    vector<ll> line(n+1,0),row(n+1,0);
    for(ll i=0;i<m;i++){
        ll x,y;cin>>x>>y;
        line[x]++;
        row[y]++;
    }
    ll ans=n;
    ll ans1=*max_element(line.begin(),line.end());
    ll ans2=*max_element(row.begin(),row.end());
    ans=min(ans,n-ans1);
    ans=min(ans,n-ans2);
    cout<<ans<<endl;
    return 0;
}