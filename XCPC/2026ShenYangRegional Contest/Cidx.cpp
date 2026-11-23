#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
const ll inf=LLONG_MAX;
void solve() {
    ll n,m,A,B,C;
    cin >> n >> m >> A>> B >> C;
    vector<vector<ll>> dp(m+1,vector<ll> (m+100,inf));
    const ll hit = B-A;
    const ll miss= C-A;
    ll ans=0;
    vector<ll> best(m+100,inf);
    dp[0][0] = best[0] = 0;
    for(ll i=0;i<n;i++){
        ll x;
        cin >> x;
        for(ll y=0;y<=m;y++){
            if(y==x)continue;
            ll val = dp[x][y];
            ll hitbase = min(dp[x][y],dp[y][x]);
            //缓存命中之后都会变成[x][y];
            if(hitbase!=inf){
                val = min(val,hitbase + hit);
            }
            if(best[y]!=inf) {
                val=min(val,best[y] + miss);
            }
            dp[x][y] = val;
            best[x] = min(best[x],val);
        }
        ans=min(ans,best[x]);
    }
    cout << n * A + ans <<endl;
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
/* Input 
1
4
2 2 1 2 3
1 1
4 2 2 1 3
1 1 1 2
5 3 4 1 2
1 2 2 3 1
5 3 3 1 4
1 2 2 3 1
Output 
1
2
7
9
13 
*/