#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a.begin()+1,a.end(),greater<ll>());
    vector<ll> pre(n + 1, 0), ans(n + 1, 0);
    for(ll i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    ll l=1;
    for(ll k=n;k>=3;k--){
        l=1;
        while(l+k-1<=n){
            
            ll r=l+k-1;
            ll cur=pre[r]-pre[l-1];
            ll val=pre[r]-pre[l];
            if(val>a[l]){
                ans[k]=cur;
                break;
            }else {
                l++;
            }
        }

    }


    for (ll k = 1; k <= n; k++) {
        cout << ans[k] << " ";
    }
    cout << endl;
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