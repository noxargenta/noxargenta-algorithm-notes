#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){   
    for(ll n=1000050;n<=1000050;n++){
        for(ll a=1;a<=1000;a++){
            for(ll b=1;b<=1000;b++){
                for( ll c=1;c<=1000;c++){
                    if(n==(a+b)*(a*b)+(b+c)*(b*c)+(a+c)*a*c){
                        cout << "n:" << n << " " << a  << " " << b <<" "  << c << " "<< endl; 
                    };
                }
         
            }
        }
        cout << "n:"<<n << " ";
        cout << -1 <<endl;
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