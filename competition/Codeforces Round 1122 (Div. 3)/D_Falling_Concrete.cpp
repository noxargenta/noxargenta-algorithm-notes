#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n,0);
    for(ll i=0;i<n;i++){
        ll x;
        cin >> x;

        a[i]=x-(i+1);
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    ll max_l=1;
    ll cur=1;
    for(ll i=1;i<a.size();i++){
        if(a[i]==a[i-1]+1){
            cur++;
        }else {
            cur=1;
        }
        max_l=max(cur,max_l);
    }
    cout << max_l <<endl;
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