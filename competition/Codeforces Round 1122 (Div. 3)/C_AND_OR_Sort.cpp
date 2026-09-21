#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
bool check(string s){
    char now=s[0];
    for(auto x : s){
        if(now=='1' && x!='1'){
            return 0;
        }
        if(x=='1'){
            now='1';
        }
    }
    return 1;
}
void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if(check(s)){
        cout << 0 <<endl;
    }
    if(s[0]=='1'){
        ll ans=0;
        for(ll i=0;i<n;i++){
            if(s[i]=='0'){
                ans++;
            }
        }
        cout << ans <<endl;
        return;
    }
    if(s[n-1]=='0'){
        ll ans=0;
        for(ll i=0;i<n;i++){
            if(s[i]=='1'){
                ans++;
            }
        }
        cout << ans <<endl;
        return;
    }
    vector<ll> pre1(n+2,0);
    vector<ll> pre0(n+2,0);
    for(ll i=0;i<n;i++){
        if(s[i]=='1'){
            pre1[i+1]=pre1[i] + 1;
        }else {
            pre1[i+1]=pre1[i];
        }
    }
    for(ll i=n-1;i>=0;i--){
        if(s[i]=='0'){
            pre0[i+1]=pre0[i+2]+1;
        }else {
            pre0[i+1]=pre0[i+2];
        }
    }
    ll ans=LLONG_MAX;
    for(ll i=0;i<n;i++){
        ans=min(ans,min(pre1[i+1],pre0[i+1]));
    }
    cout << ans <<endl;
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