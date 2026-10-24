#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    s=" "+s;
    const ll B=1313;
    const ll MOD1=1000000007;
    const ll MOD2=1000000009;
    vector<ll> p1(n+1,1),p2(n+1,1);// B 的幂
    vector<ll> h1(n+1),h2(n+1);
    vector<ll> one1(n+1),one2(n+1);
    vector<ll> cnt(n+1);
    for(ll i=1;i<=n;i++){
        ll x=s[i]-'0';

        //p表示在MOD意义下B的i次方的值是p[i];
        p1[i]=p1[i-1]*B%MOD1;
        p2[i]=p1[i-1]*B%MOD2;

        //原串Hash前缀
        h1[i]=(h1[i-1] * B + x) %MOD1;
        h2[i]=(h2[i-1] * B + x) % MOD2;

        //长度为i的全1字符串hash
        one1[i]=(one1[i-1] * B + 1) % MOD1;
        one2[i]=(one2[i-1] * B + 1) % MOD2;
        
        // cnt表示前i个字符中1的个数
        cnt[i]=cnt[i-1] + x;
    }
    auto cal = [&](ll l,ll r,vector<ll> &p,
        vector<ll> &h,
        vector<ll> &one,ll mod)-> ll {
        ll len=r-l+1;
        // k 为区间内1的个数
        ll k = cnt[r]-cnt[l-1];
        ll left = h[l-1];
        //区间内排序之后的“1”段的hash
        //例如01011
        //变为00111
        //Hash=hash("111");
        ll mid = one[k];
        ll right = (h[n]-h[r] * p[n-r] % mod + mod)%mod;

        ll res = (left * p[len])
        
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