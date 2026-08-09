#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n,q,x;
    cin >> n>> q >> x;
    vector<ll > a(n);
    ll sum=0;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        a[i]=abs(a[i]-x);
        sum+=a[i];
    }
    sort(a.begin(),a.end(),greater());
    
    while(q--){
        ll k;
        cin >> k;
        ll ans=0;
        ll sum2=sum;
        for(ll i=0;i<n;i++){
            if(sum2<=k){
                break;
            }
            sum2-=a[i];
            ans++;
        }
        if(sum2<=k){
            cout << ans << endl;
        }else {
            cout << -1 <<endl;
        }

    }
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