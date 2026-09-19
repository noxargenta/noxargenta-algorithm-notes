#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){   
    for(ll i=0;i<1000;i++){
        for(ll j=0;j<1000;j++){
            for(ll ii=0;ii<1000;ii++){
                for( ll jj=0;jj<1000;jj++){
                    if(ii !=i && ii !=j){
                        if(i+j==ii+jj && i*j==ii*jj){
                            cout << i << j << ii << jj <<endl;
                        }
                    }
                }
            }
        }
    }
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