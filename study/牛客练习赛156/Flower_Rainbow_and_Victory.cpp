#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    string s1;
    string s2;
    cin >> s1 >>s2;
    ll r=0,f=0,d=0;
    for(ll i=0;i<n;i++){
        ll a0=0,ab=0,a1=0,ar=0;
        if(s1[i]=='0'){
            a0++;
        }else {
            a1++;
        }
        if(s2[i]=='B'){
            ab++;
        }else {
            ar++;
        }
        if(a0+ab !=0 && a1 + ar !=0){
            d++;
        }else {
            if(a0+ab!=0){
                r++;
            }else {
                f++;
            }
        }
    }
    ll ansr=(d+2-1)/2;
    ll ansf=d/2;
    if(r>f){
        ansr+=(abs(r-f)+2-1)/2;
        ansf+=(abs(r-f)/2);
    }else if(){
        
    }

}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}