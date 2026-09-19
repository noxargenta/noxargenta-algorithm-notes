#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){   
    ll n;cin>>n;
    //cout<<sqn<<endl;
    for(ll i=1;i<100000;i++){
        for(ll j=1;j<30;j++){
            for(ll k=1;k<30;k++){
                if(n==i*j*(i+j)+i*k*(i+k)+j*k*(j+k)){
                    cout<<i<<" "<<j<<" "<<k<<endl;
                    return;
                }
            }
        }
    }
    cout<<-1<<endl;
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