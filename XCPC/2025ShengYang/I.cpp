#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void solve(){
    ll n;
    cin >> n;
    map<pair<ll,ll>,ll> mp;
    map<ll,ll> dui;
    for(ll i=1;i<=n;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        if(mp[{a,b}]==0){
            if(c<240 || (c>=240 && dui[a]<3)){
                cout << b <<endl;
            }else {
                cout << 0 <<endl;
            }
        }else {
            cout << 0 <<endl;
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll _=1;
    //cin >> _;
    while(_--){
        solve();
    }
}