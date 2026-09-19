#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){   
    ll n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    string s2="";
    s2+=s[0];
    s2+=s[1];
    ll hour=stoll(s2);
    if(m * 10 >= n*2 || m >=50 || hour>=4){
        cout << "YES\n"; 
        return;
    }
    cout << "NO\n";

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