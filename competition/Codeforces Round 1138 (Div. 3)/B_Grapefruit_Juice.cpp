#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n,k,p;//葡萄柚的数量、每杯果汁所需的水果数量，以及一杯果汁带来的愉悦点数。
    cin >> n >> k >> p;
    ll ans = 0;
    vector<ll> a(n+1,0);
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a.begin()+1,a.end());
    vector<ll> pre(n+1,0);
    for(ll i=1;i<=n;i++){
        pre[i] = pre[i-1] + a[i];
    }
    ll last = 0;
    ll ok=0;
    for(ll i=k;i<=n;i+=k){
        if(i+last>=k && pre[i] - pre[last] <= p){
            ans+=p;
            last = i;
        }
    }
    for(ll i=last+1;i<=n;i++){
        ans+=a[i];
    }
    cout  <<  ans << endl;

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