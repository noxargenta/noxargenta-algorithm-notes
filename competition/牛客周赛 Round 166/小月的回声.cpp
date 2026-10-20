#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n+1,0);
    vector<ll> pre(n+1,0);
    vector<ll> pos(40,-1);

    for(ll i=1;i<=n;i++){
        cin >> a[i];
        pre[i]=pre[i-1]+a[i];
        pos[pre[i]]=i;
    }
    
    ll ans=0;
    for(ll i=1;i<=n;i++){
        for(ll v=1;v<=30;v++){
            ll l=i;
            ll tar=pre[i]+a[i]*v;
            if(tar>pre[n])break;
            ll k=pos[tar];
            if(k==-1)continue;
            ll r=k+1;
            if(r-l>=2 && r<=n && a[r]==v){
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