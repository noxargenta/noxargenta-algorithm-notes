#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    string s;
    cin >> s;
    s=" "+s;
    ll n=s.length()-1;
    vector<ll> a(n+10,0);
    vector<ll> pre(n+10,0);
    for(ll i=1;i<n;i++){
        if(s[i]==s[i+1]){
            a[i]++;
        }
    }
    for(ll i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    ll q;
    cin>> q;
    while(q--){
        ll l,r;
        cin >> l >> r;
        cout << pre[r-1]-pre[l-1] <<endl;
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