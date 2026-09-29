#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
bool check(ll x){
    ll sum=0;
    while(x){
        ll val=x%10;
        x/=10;
        sum+=val;
        if(sum>10){
            return 0;
        }
    }
    if(sum==10){
        return 1;
    }else {
        return 0;
    }
}
void solve() {
    ll n;
    cin >> n;
    ll cnt=0;
    ll ans=19;
    while(cnt<n-1){
        ans+=9;
        if(check(ans)){
            cnt++;
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