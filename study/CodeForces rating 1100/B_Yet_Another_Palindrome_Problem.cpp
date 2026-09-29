#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
vector<bool> vis(6000,0);
vector<ll> pos(6000,-1);
void solve() {
    fill(vis.begin(),vis.end(),0);
    fill(pos.begin(),pos.end(),-1);
    ll n;
    cin >> n;
    vector<ll> a(n+1,0);
    for(ll i=1;i<=n;i++){
        cin  >> a[i];
    }
    for(ll i=1;i<=n;i++){
        if(vis[a[i]]==0){
            vis[a[i]]=1;
            pos[a[i]]=i;
        }else {
            if(i-pos[a[i]]>1){
                //cout << i<<endl;
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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