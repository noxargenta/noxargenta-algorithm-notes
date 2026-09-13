#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
ll n;
vector<ll> a;
map<ll,ll> cnt;
ll mex(){
    
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