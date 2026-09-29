#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    string s;
    cin >> s;
    s=" "+ s;
    ll n=s.length()-1;
    ll last=0;
    ll ans=0;
    for(ll i=0;i<=n;i++){
        if(s[i]=='R'){
            ans=max(ans,i-last);
            last=i;
        }else {
            continue;
        }
    }
    ans=max(ans,n+1-last);
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