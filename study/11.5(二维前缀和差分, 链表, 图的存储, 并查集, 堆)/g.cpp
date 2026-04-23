#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
vector<unsigned long long> w[500010];
void solve() {
    int n,m,u,v;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        w[i].clear();
    }
    for(int i=1;i<=m;i++){
        cin >> u >> v;
        w[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        sort(w[i].begin(),w[i].end());
        for(int j=0;j<w[i].size();j++){
            cout << w[i][j] << " ";
        }
        cout << endl;
    }
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