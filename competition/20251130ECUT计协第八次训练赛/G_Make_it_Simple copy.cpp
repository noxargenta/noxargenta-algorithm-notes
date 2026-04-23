#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    set<pair<int,int>> a;
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        if(u==v){
            continue;
        }
        if(u>v){
            swap(u,v);
        }
        a.insert({u,v});
    }
    cout << m-a.size();
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