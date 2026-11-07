#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
ll c(ll x,ll k){
    
}
void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll a=0;
    ll b=0;
    ll cnt0=0;
    ll cnt1=0;
    for(ll i=0;i<n-1;i++){
        if(s[i]=='0'){
            cnt0++;
        }else {
            cnt1++;
        }
        if(s[i]!=s[i+1]){
            
            if(s[i]=='0'){
                a++;
            }else {
                b++;
            }
        }
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