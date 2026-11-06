#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n;
    cin >> n;

    ll cnt=0;
    ll s;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++){
        cin >> a[i];
        s^=a[i];
        if(a[i]!=0){
            cnt++;
        }    
    }

    if(n==1){
        cout << 0 <<endl;
    }else if(s==0){
        cout << 1 <<endl;
    }else{
        ll ans=0;
        for(auto x : a){
            if(x^s<x){
                ans++;
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