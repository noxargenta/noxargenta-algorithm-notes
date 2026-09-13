#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
ll n;
vector<ll> a;
unordered_map<ll,ll> cnt;
ll mex(){
    vector<ll> vis(n+1,0);
    for(auto x : a){
        if(x>=0 && x <=n){
            vis[x]=1;
        }
    }
    for(ll i=0;i<=n;i++){
        if(!vis[i]){
            return i;
        }
    }
    return n;
}
void solve() {
    cin >> n;
    a.resize(n);
    cnt.clear();

    for(ll i=0;i<n;i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    ll M=mex();
    for(auto ai : a){
        ll j=M+ai;
        if()
    }
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