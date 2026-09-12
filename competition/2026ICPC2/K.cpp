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
    ll ans=-1;
    ll val=0;
    sort(b.begin(),b.end());
    for(ll i=0;i<=5000+5;i++){
        if(mp[i]==0){
            if(ans==-1){
                ans=i;
            }
            pq.push(i);
        }
    }
    map<ll,ll> kan;
    
    while(q--){
        ll k;
        cin >> k;
        if(kan[k]!=0){
            val^=kan[k];
            continue;
        }
        vector<ll> a=b;
        map<ll,ll> mp2=mp;
        priority_queue<ll,vector<ll>,greater<ll>> pq2=pq;
        ll idx=lower_bound(a.begin(),a.end(),k)-a.begin();
        if(idx==a.size()){
            idx=n-1;
        }
        for(ll i=idx;i>=0;i--){
            // for(ll j=0;j<n;j++){
            //     cout << a[j] << " ";
            // }
            // cout << endl;
            
            ll cur=k-a[i];
            if(cur<0){
                continue;
            }

            if(mp2[a[i]]>1 &&  mp2[cur]==0){
                mp2[cur]++;
                mp2[a[i]]--;
                while(pq2.size()){
                    if(mp2[pq2.top()]!=0){
                        pq2.pop();
                    }else {
                        break;
                    }
                }
            }else if(mp2[a[i]]==1 && mp2[cur]==0 && a[i]>cur){
                mp2[cur]++;
                mp2[a[i]]--;
                while(pq2.size()){
                    if(mp2[pq2.top()]!=0){
                        pq2.pop();
                    }else {
                        break;
                    }
                }
                pq2.push(a[i]);
            }
            
        }

        //cout <<"pq2.top():" <<pq2.top() << endl;
        val ^= pq2.top();
        kan[k]=pq2.top();
        // for(ll j=0;j<n;j++){
        //     cout << a[j] << " ";
        // }
        // cout << endl;
    }
    cout << val << endl;

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