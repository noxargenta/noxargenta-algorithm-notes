#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
     ll n;
    cin >> n;
    unordered_set<ll> s;
    for(ll i=0;i<n;i++){
        ll x;
        cin >> x;
        s.insert(x);
    }
    for(auto x : s){
        cout << x <<  " "; 
    }
    cout <<endl;
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