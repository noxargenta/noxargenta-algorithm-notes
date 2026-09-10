


#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct node{
    ll x;
    ll y;
    ll b[2];
};
void solve(){
    vector<node> a(2);
    a[0].x=3;
    a[0].b[0]=1;
    a[0].y=999;
    a[1].x=1;
    a[1].b[1]=2;
    a[1].y=854;
    sort(a.begin(),a.end(),[&](node l ,node r){
        return l.x < r.x;
    });
    for(auto x : a){cout << x.x << " ";}
    cout << endl;
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