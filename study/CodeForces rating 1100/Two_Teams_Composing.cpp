#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    map<ll,ll> mp;
    set<ll> st;
    ll maxx=0;
    ll ans;
    if(n<=1){
        cout << 0 <<endl;
        return;
    }
    for(ll i=0;i<n;i++){
        ll x;
        cin >> x;
        if(!mp.count(x)){
            maxx++;
        }
        st.insert(x);

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