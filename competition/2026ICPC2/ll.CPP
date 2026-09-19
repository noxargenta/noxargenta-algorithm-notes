#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n;
    cin >> n;
    ll a[n],b[n];
    vector<ll>sa(n),sb(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
        if(i==0){
            sa[i]=a[i];
        }else{
            sa[i]=sa[i-1]+a[i];
        }
    }
    if(n==1){
        cout<<a[0]<<'\n';
        return;
    }
    b[0]=a[0];
    sb[0]=a[0];
    for(ll i=1;i<n;i++){
        b[i]=a[n-i];
        sb[i]=sb[i-1]+b[i];
    }
    ll ans=LLONG_MAX;
    
    for(ll i=0;i<n-1;i++){
        
        ll res=(n-i)*a[i]+(n-i-1)*(a[i+1]);
        ll cur=(n-i)*b[i]+(n-i-1)*(b[i+1]);
        if(i>0){
            res+=sa[i-1]*2;
            cur+=sb[i-1]*2;
        }
        ans=min(ans,min(cur,res));
        
    }
    cout<<ans<<"\n";
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
// 13
// 7
// 20
// 30
// 7
// 24
// 705032704