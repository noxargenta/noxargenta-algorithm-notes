#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
ll mod=998244353;
auto qpow(ll x,ll k){
    ll ans=1;
    while(k>0){
        if(k%2!=0){
            ans=ans*x%mod;
            k--;
        }else {
            k/=2;
            x=x*x%mod;
            ans=ans*x%mod;
        }
    }
    return ans;
}
void solve() {
    ll a,b,n,m;
    cin >> a >> b >> n >> m;
    ll k=(a*b)-(a-n+1)*(m-b+1);
    cout << qpow(2LL,k) <<endl;
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