#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll x;
    cin >> x;
    if(x<=3){
        cout << -1  << endl;
    }else {
        cout << 4 << " " ;
        ll cnt=2;
        for(ll i=x;i>=2;i--){
            if(i==4)continue;
            
            if(cnt==4){
                cout << 1 << " ";
            }
            cnt++;
            cout << i <<  " ";
        } 
        cout <<endl;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll _=1;
    cin >> _;
    while(_--){
        solve();
    }
}