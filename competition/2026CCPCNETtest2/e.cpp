#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve(ll x) {
    if(x==0){
        ll n;
        cin >> n;
        vector<ll> a(n+1,0);
        for(ll i=1;i<=n;i++){
            cin >> a[i];
        }
        
    }
}

signed main(int,char* argv[]) {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    ll x=argv[1][0]-'0';
    while(_--) {
        solve(x);
    }
    return 0;
}