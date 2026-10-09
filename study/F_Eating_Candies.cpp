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
    ll l=1,r=n;
    ll sum1=0,sum2=0;
    ll ans=0;
    while(l<=r){
        sum1+=a[l];
        while(l<r && sum1 > sum2){
            sum2+=a[r];
            r--;
        }
        if(sum1==sum2){
            ans=max((l + n - r  ),ans);
        }
        l++;
    }   
    cout << ans <<endl;
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