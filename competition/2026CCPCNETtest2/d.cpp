#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define ll long long
void solve() {
    ll x;
    cin >> x;
    if(x==1){
        ll n,l;
        cin >> n >> l;
        vector<ll> a(n+1,0);
        
        vector<ll> ans;
        for(ll i=1;i<=n;i++){
            cin >> a[i];
            ll y=a[i]/l;
            ans.push_back(y);
        }
        sort(ans.begin(),ans.end(),greater<ll>());
        for(auto y : ans){
            cout << y << " ";
        }
        cout << endl;
    }else {
        ll n,k;
        cin >> n >> k;
        vector<ll> a(n+1,0);
        ll pre=0;
        for(ll i=1;i<=n;i++){
            cin >> a[i];
            pre+=a[i];
            if(pre>=k){
                cout << i <<endl;
                return;
            }
        }
        cout << -1 <<endl;
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