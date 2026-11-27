#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    vector<ll> b(n);
    for(ll i=0;i<n;i++){
        cin >> b[i];
    }
    ll dp[n+1];
    dp[n]=0;
    for(ll i=n-1;i>=0;i--){
        dp[i] = max(dp[i+1] + a[i] - b[i] , -dp[i+1]);
    }
    if(dp[0]>0){
        cout << "Sunny" << endl;
    }else if(dp[0]<0){
        cout << "Aubrey" << endl;
    }else {
        cout << "Draw" << endl;
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