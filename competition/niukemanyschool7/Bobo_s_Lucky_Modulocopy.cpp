#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    ll ans=0;
    for(ll b=1;b*b<=n;b++){
        ll t=b*(b+1);
        ll cnt=n/t;
        ll ini=cnt*b;
        ans+=ini;
        ll scnt=n%t;
        
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