#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
    ll n;cin>>n;
    map <ll,ll> mp,cnt;
    for(ll i=0;i<n;i++){
        ll t;cin>>t;
        mp[t]++;
    }
    priority_queue<ll,vector<ll>,greater<ll>> pq1;
    for(ll i=0;i<n+10;i++){
        if(mp[i]==0) {pq1.push(i);cout<<i<<" ";}
    }
    cout<<endl;
    ll ans=0;
    ll q;cin>>q;
    for(ll i=0;i<q;i++){
        ll k;cin>>k;
        cnt[k]++;
    }
    for(auto ip:cnt){
        priority_queue<ll,vector<ll>,greater<ll>> pq=pq1;
        ll k=ip.first;
        if(cnt[k]%2==0){
            continue;
        }
        else cnt[k]--;
        while(k-pq.top()>=0&&mp[k-pq.top()]!=0&&k-pq.top()>pq.top()){
            pq.pop();
            mp[k-pq.top()]--;
            if(mp[k-pq.top()]==0) pq.push(k-pq.top());
        }
        ans^=pq.top();
        cout<<pq.top()<<endl;
    }
    cout<<ans<<endl;
}
int main(){
    ll _;cin>>_;
    while(_--) solve();
    return 0;
}