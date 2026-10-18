#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    ll tmp=n-1;
    vector<ll> f(n+1);
    ll i=1;
    vector<string> a(n + 1);
    vector<vector<ll>> G(n + 1);
    for (ll i = 2; i <= n; i++) {
        ll fu;
        cin >> fu >> a[i];
        G[fu].push_back(i);
    }
    string pat;
    cin >> pat;
    ll m=pat.length();
    vector<ll> nxt(m+1);
    ll j;
    j=nxt[0]=-1;
    i=0;
    while(i<m){
        while(j!=-1 && pat[i]!=pat[j]){
            j=nxt[j];
        }
        nxt[++i]=++j;
    }
    i=0;
    j=0;

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