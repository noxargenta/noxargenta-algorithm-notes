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
    vector<ll> nxt(n+1,inf);
    
    vector<ll> pos(n+1);
    priority_queue<pair<ll,ll>,
                   vector<pair<ll,ll>>,
                   greater<pair<ll,ll>>> pq;

    for(ll i=1;i<=n;i++){
        ll j= to[i];
        if(dir[i]!=dir[j]){
            nxt[i] = abs(x[i]-x[j])/2;
            pq.push({nxt[i],i});

        }
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