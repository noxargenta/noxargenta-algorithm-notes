#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n;
    cin >> n;
    vector<ll> b(n);
    map<ll,ll> mp;   
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    for( ll i =0;i<n;i++){
        cin >> b[i];
        mp[b[i]]++;
    }
    ll q;
    cin >> q;
    ll val=0;
    sort(b.begin(),b.end());
    for(ll i=0;i<=5000+5;i++){
        if(mp[i]==0){
            pq.push(i);
        }
    }
    map<ll,ll> cnt;
    for(ll i=0;i<q;i++){
        ll k;cin>>k;
        cnt[k]++;
    }
    vector<ll> c;
    for(auto x : b){
        if(c.empty()){
            c.push_back(x);
        }else if(c.back()==x){
            continue;
        }else {
            c.push_back(x);
        }
    }
    for(auto ip:cnt){
        ll k=ip.first;
        if(cnt[k]%2==0){
            continue;
        }else { 
            cnt[k]--;
        }
        vector<ll> a=c;
        map<ll,ll> mp2=mp;
        priority_queue<ll,vector<ll>,greater<ll>> pq2=pq;
        ll idx=lower_bound(a.begin(),a.end(),k)-a.begin();
        if(idx>=a.size()){
            idx=a.size()-1;
        }
        for(ll i=idx;i>=0;i--){
            ll cur=k-a[i];
            if(cur<0){
                continue;
            }

            if(mp2[a[i]]>1 &&  mp2[cur]==0){
                mp2[cur]++;
                mp2[a[i]]--;
                while(!pq2.empty()){
                    if(mp2[pq2.top()]!=0){
                        pq2.pop();
                    }else {
                        break;
                    }
                }
            }else if(mp2[a[i]]==1 && mp2[cur]==0 && a[i]>cur){
                mp2[cur]++;
                mp2[a[i]]--;
                while(!pq2.empty()){
                    if(mp2[pq2.top()]!=0){
                        pq2.pop();
                    }else {
                        break;
                    }
                }
                pq2.push(a[i]);
            }
            
        }
        val^=pq2.top();
    }
    cout<<val<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll _=1;
    cin >> _;
    while(_--){
        solve();
    }
}