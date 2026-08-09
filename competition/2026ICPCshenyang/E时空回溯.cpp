#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >>n;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++){
        cin >>a[i];
    }
    sort(a.begin()+1,a.end());
    vector<double> w(n+1);
    double ans=LLONG_MAX;
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            if(i<=k){
                w[i]=k-i+1+(n-k)/2.0;
            }else {
                w[i]=n-i+1;
            }
            
        }
        
        sort(w.begin()+1,w.end(),greater());
        double now=0;
        for(ll i=1;i<=n;i++){
            now+=a[i]*w[i];
        }
        ans=min(ans,now);
    }
    cout << fixed << setprecision(1) << ans <<endl;
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