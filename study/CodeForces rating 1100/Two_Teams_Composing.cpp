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
    ll cnt=0;
    if(n<=1){
        cout << 0 <<endl;
        return;
    }
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    ll cur=0;
    ll now;
    for(ll i=0;i<n;i++){
        if(!mp[a[i]]){
            now=a[i];
            ll cur=0;
            mp[a[i]]++;
            st.insert(a[i]);
        }
        if(now==a[i]){
            cur++;
        }
        maxx=max(maxx,cur);
    }
    cout << max(min((ll)st.size()-1,maxx),min((ll)st.size()-1+1,maxx-1));
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