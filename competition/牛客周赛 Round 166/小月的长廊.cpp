#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n,p;
    cin >>n >> p;
    ll maxx=0;
    vector<pair<ll,ll>> a(n);
    vector<ll> dif(n+100,0);
    for(ll i=0;i<n;i++){
        cin >>a[i].first >> a[i].second;
        maxx=max(a[i].second,maxx);
        dif[a[i].first]++;
        dif[a[i].second+1]--;
    }
    vector<ll> b(maxx+100,0);
    ll val=0;
    for(ll i=0;i<=maxx;i++){
        
        b[i]+=dif[i]+b[i==0 ? 0 : i-1];
        // for(ll k=0;k<maxx;k++){
        //     cout << b[k]  << " ";
        // }
        // cout <<endl;
    }
    ll ans2=0;
    for(ll i=0;i<n;i++){
        if(abs(b[a[i].first]-b[a[i].second])>=p){
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