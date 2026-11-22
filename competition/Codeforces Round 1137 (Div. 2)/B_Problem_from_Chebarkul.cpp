#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n+1);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    ll x=n-k+1;
    ll last=-1;
    ll cnt=1;
    vector<ll> al(n+1);
    for(ll i=0;i<n;i++){
        if(a[i]==last){
            cnt++;
        }else {
            cnt=1;
            
        }
        al[i]=cnt;
        last=a[i];

    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        if(al[i]>=x){
            ans++;
        }
    }
    cout << ans << endl;
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