#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
// p[i]表示i位置放队伍p[i]
ll a[8+1],b[8+1];
vector<ll> p(8+1);
vector<ll> dp(9,1);
void dfs(ll l,ll r){
    if(l==r){
        dp[l]=1;
        return;
    }
    ll mid=(l+r)/2;
    dfs(l,mid);
    dfs(mid,r);
    double tmp[9]={};
    for(ll i=l;i<=mid;i++){
        for(ll j=mid+1;j<=r;j++){
            double x=a[p[i]],y=b[p[j]];
            double meet = dp[i] * dp[j];

            tmp[i]+=meet * x/(x+y);
            tmp[j]+=meet * y/(x+y);



        }
        for(ll i=l;i<=r;i++){
            dp[i]=tmp[i];
        }
    }   
}
void solve() {
    ll n=8;
    for(ll i=1;i<=8;i++){
        p[i]=i;
    }
    
    for(ll i=1;i<=n;i++){
        cin >> a[i] >> b[i];
    }
    double ans=0;
    do
    {
        dfs(1,8);
        for(ll i=1;i<=n;i++){
            if(p[i]==0){
                ans=max(ans,dp[p[i]]);
            }
        }
    } while (next_permutation(p.data()+1,p.data()+1+8));
    
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