#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n;
    cin >> n;
    vector<ll> to(n+1);
    vector<vector<ll>> rev(n+1);
    for(ll i=1;i<=n;i++){
        cin >> to[i];
        rev[to[i]].push_back(i);
    }
    vector<ll> x(n+1);
    for(ll i=1;i<=n;i++){
        cin >> x[i];
        x[i]*=2;
    }
    vector<ll> dir(n+1);
    for(ll i=1;i<=n;i++){
        if(to[i]>i){
            dir[i]=1;
        }else {
            dir[i]=-1;
        }
    }
    ll inf=LLONG_MAX;
    //nxt[i]表示第i只企鹅当前情况追到目标企鹅的时间是nvt[i];
    vector<ll> nxt(n+1,inf);
    
    vector<ll> pos(n+1);
    priority_queue<pair<ll,ll>,
                   vector<pair<ll,ll>>,
                   greater<pair<ll,ll>>> pq;

    vector<ll> ans(n + 1, -1);
///////////////
    //初始化
    for(ll i=1;i<=n;i++){
        ll j= to[i];
        if(dir[i]!=dir[j]){
            nxt[i] = abs(x[i]-x[j])/2;
            pq.push({nxt[i],i});
        }
    }

    while(!pq.empty()){
        auto [tm,u] = pq.top();
        pq.pop();

        if(ans[u]=-1 || tm != nxt[u]) continue;
        ans[u] = tm;
        
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