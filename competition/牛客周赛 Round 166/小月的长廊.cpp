#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n,p;
    cin >>n >> p;
    vector<pair<ll,ll>> a(n);
    vector<ll> dif(n+100,0);
    for(ll i=0;i<n;i++){
        cin >>a[i].first >> a[i].second;
        dif[a[i].first]++;
        dif[a[i].second+1]--;
    }
    vector<ll> ans(n+100,0);
    ll val=0;
    for(ll i=0;i<n;i++){
        val+=dif[i];
        ans[i]+=val;
        for(ll k=0;k<n;k++){
            cout << ans[k]  << " ";
        }
        cout <<endl;
    }
    ll ans2=0;
    for(ll i=0;i<n;i++){
        if(abs(ans[a[i].first]-ans[a[i].second])>=p){
            ans2++;
        }
    }
    cout << ans2 <<endl;

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