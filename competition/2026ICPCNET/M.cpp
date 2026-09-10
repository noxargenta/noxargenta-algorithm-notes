#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll n,m;
    cin >> n >>  m;
    map<string ,ll > mp;
    for(ll i=0;i<n;i++){
        string s;
        cin >>s;
        mp[s] ++ ;
    }
    for(ll i=0;i<m;i++){
        string s;
        cin >>s;
        if(mp[s]==1){
            cout << "OK\n";
            mp[s]++;
        }else if(mp[s]==0){
            cout << "WRONG\n";
        }else{
            cout << "REPEAT\n";
            mp[s]++;
        }
    }
    return 0;
}