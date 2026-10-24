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
        p1[i]=p1[i-1]*B%MOD1;
        
        p1[i]=p1[i-1]*B%MOD2;

        
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