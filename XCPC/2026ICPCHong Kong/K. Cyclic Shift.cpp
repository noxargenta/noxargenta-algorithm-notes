#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n;
    cin >> n;
    ll mn=LLONG_MAX;
    vector<ll> a(2*n+10);
    vector<ll> mx(n+10,-1);
    for(ll i=1;i<=n;i++){
        cin >> a[i];
        a[i+n]=a[i];
        mn=min(mn,a[i]);
    }
    //nq为候选起点
    vector<ll> q,nq;
    
    //q最小的a[i]作为起点，存的是下标
    for(ll i=1;i<=n;i++){
        if(a[i]==mn){
            q.push_back(i);
            mx[i]=a[i];
        }
    }
    for(ll i=1;i<n && q.size()>1;i++){
        mn=LLONG_MAX;
        // x是起点的位置 
        for(auto x : q){
            mx[x]=max(mx[x],a[x+i]);
            mn=min(mn,mx[x]);

        }
        nq.clear();
        for(auto x : q){
            if(mx[x]!=mn)continue;

            if(!nq.empty() && x -nq.back()<=i)continue;

            nq.push_back(x);

        }
        swap(q,nq);

    }
    ll s=q[0],ans=0;
    for(ll i=0;i<n;i++){
        ans=max(ans,a[s+i]);
        cout << ans << " ";
    }
    cout << endl;
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