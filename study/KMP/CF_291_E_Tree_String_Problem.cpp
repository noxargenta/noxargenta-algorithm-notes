#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    ll tmp=n;
    vector<string> a(n+1,"");
    vector<ll> f(n+1);
    ll i=1;
    string pat;
    vector<vector<ll>> G(n+10,vector<ll> (0));
    while(tmp--){
        i++;
        ll fu;
        cin >> fu;
        cin >> a[i];
        f[i]=fu;
        ll u=i,v=fu;
        G[v].push_back(u);
        G[u].push_back(v);
    }   
    cin >> pat;
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