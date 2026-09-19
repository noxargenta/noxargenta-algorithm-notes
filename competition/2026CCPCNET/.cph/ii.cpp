#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
bool check(ll x ){
    if((x+x)*x*x*3>n){
        return 1;
    }
    return 0;
}
void solve(){   
    
    cin >> n;
    cout << "n:" <<n << " ";
    if(n<6){
        cout << -1 <<endl;
        return;
    }
    ll l=1,r=n-1;
    while(l<r){
        ll mid=(l+r)/2;
        if(check(mid))r=mid;
        else {
            l=mid+1;
        }
    }
    //cout << l << r;
    ll lef;
    ll rig=r;
    for(ll i=rig;i>=1;i--){
        if((i+i)*i*i*3<=n){
            lef=i;
        }
    }
    cout << lef << " " << rig << " ";
    for(ll i=lef;i<=rig;i++){
        for(ll j=i;j<=rig;j++){
            for(ll k=j;k<=rig;k++){
                if(n==(i+j)*(i*j)+(j+k)*(j*k)+(i+k)*i*k){
                    cout << i << " " << j << " " << k << endl;
                    return;
                }
            }
        }
    }
    cout << -1 <<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll _=1;
    //cin >> _;
    while(_--){
        solve();
    }
}