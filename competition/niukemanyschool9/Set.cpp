#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    ll ct0=0;
    ll ct1=0;
    ll a[n];
    set<ll> st;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        st.insert(a[i]);
        if(a[i]%2==0){
            ct0++;
        }else {
            ct1++;
        }
    }
    ll ans=0;
    for(auto x : st){
        if(x%2==1){
            if(ct1%2==1){
                ans++;
            }
        }else {
            if(ct1%2==0){
                ans++;
            }
        }
    }
    cout << ans <<endl;

}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}