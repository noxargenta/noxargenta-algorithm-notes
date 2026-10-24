#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
pair<ll,ll> ger(ll x,ll y){
    ll t=__gcd(x,y);
    x/=t;
    y/=t;
    return {x,y};
}
void solve() {
    ll n;
    string s;
    cin >> s;
    map<pair<ll,ll>,ll> mp;
    ll d=0;
    ll k=0;
    for(ll i=0;i<n;i++){
        if(s[i]=='D'){
            d++;
        }else k++;
        
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