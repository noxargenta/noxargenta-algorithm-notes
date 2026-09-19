#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Node{
    ll a,b,c;
};
vector<Node> a(1e18,{-1,-1,-1});
void solve(){   
    for(ll n=1;n<=300;n++){
        for(ll a=1;a<=500;a++){
            for(ll b=1;b<=500;b++){
                for( ll c=1;c<=500;c++){
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