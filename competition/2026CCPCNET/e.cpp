#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=1e9+7;
void solve(){   
    ll n;
    cin  >> n;
    vector<ll> a(n+1,0);
    vector<ll> b(n+1,0);
    vector<ll> c(n+1,0);
    vector<ll> prea(n+1,0);
    vector<ll> preb(n+1,0);
    vector<ll> prec(n+1,0);
    vector<ll> xa(n+1,1);
    vector<ll> xb(n+1,1);
    vector<ll> xc(n+1,1);
    for(ll i=1;i<=n;i++){
        cin >> a[i];
        prea[i]=a[i]+prea[i-1];
        xa[i]=(a[i])^(xa[i-1]);
    }
    for(ll i=1;i<=n;i++){
        cin >> b[i];
        preb[i]=b[i]+preb[i-1];
        xb[i]=(b[i])^(xb[i-1]);
    }
    for(ll i=1;i<=n;i++){
        cin >>c[i];
        prec[i]=c[i]+prec[i-1];
        xc[i]=(c[i])^(xc[i-1]);
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ll cur=0;
        if(prea[i]==preb[i] && xa[i]==xb[i]){
            cur++;
        }
        if(prea[i]==prec[i] && xa[i]==xc[i]){
            cur++;
        }
        if(preb[i]==prec[i] && xb[i]==xc[i]){
            cur++;
        }
        if(cur>=1){
            ans++;
        }
    }
    cout << ans << endl;
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