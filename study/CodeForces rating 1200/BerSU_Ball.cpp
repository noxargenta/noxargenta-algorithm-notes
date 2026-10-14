#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n+1,0);
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a.begin()+1,a.end());
    ll m;
    cin >> m;
    vector<ll> b(m+1,0);
    for(ll i=1;i<=m;i++){
        cin >> b[i];
    }
    sort(b.begin()+1,b.end());
    ll aa=1,bb=1;
    ll ans=0;
    while(aa!=n && bb!=n){
        if(abs(a[aa]-b[bb])<=1){
            ans++;
            aa++;
            bb++;
        }else {
            
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