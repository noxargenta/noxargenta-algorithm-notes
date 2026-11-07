#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
const ll mod=998244353;
ll fac[(ll)1e6+10];
ll ifac[(ll)1e6+10];
auto qpow(ll x,ll k){
    ll ans=1;
    x%=mod;
    while(k>0){
        if(k&1){
            ans=ans*x%mod;
        }
        x=x*x%mod;
        k/=2;
    }
    return ans;
}
ll c(ll x,ll k){
    ll ans=1;
    for(ll i=x;i>k;i--){
        ans=ans*i%mod;

    }
    for(ll i=k;i>1;i--){
        ans=ans*ifac[i]%mod;
    }
    return ans;
}
void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll a=0;
    ll b=0;
    ll cnt0=0;
    ll cnt1=0;
   
    for(ll i=0;i<n-1;i++){
        if(s[i]=='0'){
            cnt0++;
        }else {
            cnt1++;
        }
        if(s[i]!=s[i+1]){
            
            if(s[i]=='0'){
                a++;
            }else {
                b++;
            }
        }
    }
    cout << c(a-1,cnt0-1)*c(b-1,cnt1-1) <<endl;
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     fac[1]=1;
    fac[0]=1;
    ifac[1]=qpow(1,mod-2);
    for(ll i=2;i<=1e6+1;i++){
        fac[i]=fac[i-1]*i;
        ifac[i]=qpow(i,mod-2);
    }
    
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}