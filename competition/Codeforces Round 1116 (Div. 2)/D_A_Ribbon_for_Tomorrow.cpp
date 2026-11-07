//https://codeforces.com/contest/2256/problem/D
/*
4
5
00110
6
001010
5
01010
6
111111


2
3
1
1
*/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
ll MAXX=1000000;
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
    ans=ans*(fac[x]%mod*ifac[k]%mod * ifac[x-k]%mod) %mod;
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
   
    for(ll i=0;i<n;i++){
        if(s[i]=='0'){
            cnt0++;
        }else {
            cnt1++;
        }
        if(i==n-1 ||  s[i]!=s[i+1]){
            
            if(s[i]=='0'){
                a++;
            }else {
                b++;
            }
        }
    }
    if(cnt1==0 || cnt0==0){
        cout << 1 <<endl;
        return;
    }
    cout << c(cnt0-1,a-1)*c(cnt1-1,b-1)%mod <<endl;
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fac[0]=1;
    ifac[0]=1;
    for(ll i=1;i<=1e6+1;i++){
        fac[i]=fac[i-1]*i%mod;
        ifac[i]=qpow(fac[i],mod-2);
    }
    /*
    fac[0] = 1;
    for (ll i = 1; i <= MAXX; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }

    // 修改：只求一次最大阶乘的逆元
    ifac[MAXX] = qpow(fac[MAXX], mod - 2);

    // 修改：倒着递推其余逆阶乘，也会算出 ifac[0] = 1
    for (ll i = MAXX; i >= 1; i--) {
        ifac[i - 1] = ifac[i] * i % mod;
    }
    这样算也是可以的
    */
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}