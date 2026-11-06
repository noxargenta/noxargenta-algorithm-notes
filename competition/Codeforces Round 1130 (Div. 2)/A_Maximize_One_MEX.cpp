#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long

void solve() {
    ll n,k;
    cin >> n>> k;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++){
        cin >>a[i];
        
    }
    
    auto mex = [&](ll x) -> ll{
        set<ll> st;
        ll mexx=0;
        for(ll i=1;i<=x;i++){
            st.insert(a[i]);
        }
        while(st.count(mexx)){
            ++mexx;
        }
        return mexx;
    };
    ////
    ll ans=mex(k);
    ll ans1=-1;
    ll ans2=-1;
    for(ll i=1;i<=n;i++){
        for(ll j=i+1;j<=n;j++){
            swap(a[i],a[j]);
            ll cur=mex(k);
            if(cur>ans){
                ans1=i;
                ans2=j;
            }
            ans=max(ans,cur);
            swap(a[i],a[j]);
        }
    }
    if(ans1!=-1){
        cout << ans1 << " " << ans2 << endl;
    }else{
        cout << -1 << endl;
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