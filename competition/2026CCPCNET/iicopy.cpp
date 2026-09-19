#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;

void solve(){   
    cin >> n;
    for(ll i=1;i<=1e9;i++){
        for(ll j=i;j<=1e9;j++){
            for(ll k=j;k<=1e9;k++){
                if(n==(i+j)*(i*j)+(j+k)*(j*k)+(i+k)*i*k){
                    cout << i << " " << j << " " << k << endl;
                    return;
                }
                if(1e18<(i+j)*(i*j)+(j+k)*(j*k)+(i+k)*i*k){
                    cout << "-1\n"; 
                    return;
                }
            }
        }
    }
    cout << "-1\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll _=100;
    //cin >> _;
    while(_--){
        solve();
    }
}