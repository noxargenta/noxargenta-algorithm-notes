#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n=6;
    vector<ll> a(n+1),b(n+1);
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    ll k;
    cin >> k;
    ll sum=LLONG_MAX;
    vector<ll> ans;
    //idx是当前这一层的骰子第idx面
    //cur是候选下标从哪里开始尝试
    //sum1 是当前赢的次数  sum2是当前这个骰子数值的总和
    auto dfs = [&](auto &&self,ll idx,ll cur,ll sum1, ll sum2)->void{
        if(idx>n){
            if(sum1 >= 19 && sum2 <= k){
                sum=sum2;
                ans=b;
            }
            return;
        }
        for(ll i=cur;i<=6;i++){
            b[idx]=a[i]+1;
            self(self,idx+1,sum1+i,sum2+b[idx]);
        }
    };
    dfs(dfs,1,0,0,0);
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