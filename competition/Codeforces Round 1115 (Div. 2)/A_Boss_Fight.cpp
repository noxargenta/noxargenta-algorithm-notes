#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n ;
    cin >> n;
    map<ll,ll> mp;
    ll sum=0;
    ll maxx=0;
    ll val=-1;
    for(int i=0;i<n;i++){
        ll x;
        cin >> x;
        mp[x]++;
        sum+=x;
        if(mp[x]>maxx){
            maxx=mp[x];
            val=x;  
        }
    }
    if(maxx*2<=n+1){
        cout << sum <<endl;
    }else {
        ll sum_=
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