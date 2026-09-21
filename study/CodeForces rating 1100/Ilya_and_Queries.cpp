#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    string s;
    cin >> s;
    vector<ll> a(s.length(),0);
    vector<ll> pre(s.length(),0);
    for(ll i=0;i<s.length()-1;i++){
        if(s[i]==s[i+1]){
            a[i+1]++;
        }
    }
    for(ll i=1;i<s.length();i++){
        pre[i]=pre[i-1]+a[i];
    }
    ll n;
    cin >> n;
    while(n--){
        ll l,r;
        cin >> l >> r;
        cout << pre[r]-pre[l-1] <<endl;
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