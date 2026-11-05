#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n;
    cin >> n;
    string s;
    cin >>s;
    ll ans=n-1;
    map<char,ll> mp;
    for(ll i=0;i<n;i++){
        mp[s[i]]++;
    }
    for(ll i=n-1;i>=0;i--){
        ans=min(ans,n-mp[s[i]]);
    }
    cout << ans <<endl;
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