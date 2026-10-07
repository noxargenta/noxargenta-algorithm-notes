#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<ll> dif(n+1,-1);
    for(ll i=1;i<=n;i++){
        if(dif[i-1]>i){
            dif[i]=dif[i-1];
            continue;
        }
        for(ll j=i+1;j<=n;j++){
            if(a[j]!=a[i]){
                dif[i]=j;
                break;
            }
        }
    }
    ll q;
    cin >> q;
    while(q--){
        ll l,r;
        cin >> l >> r;
        if(dif[l]!=-1 && dif[l]<=r){
            cout << l << " " << dif[l]<<endl;
        }else {
            cout << -1 << " " << -1 <<endl; 
        }

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