#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n+1);
    for(int i=1;i<=m;i++){
        int x, y ;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    if(n!=m){
        cout << "No";
        return;
    }
    for(int i=1;i<=n;i++){
        if(a[i].size()!=2){
            cout << "No";
            return;
        }
    }
    vector<bool> vis(n+1);
    for(int x=1; vis[x]==0;){
        vis[x]=1;
        for(int t : a[x]){
            if(vis[t]==0){
                x=t;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            cout << "No";
            return;
        }
    }
    cout << "Yes";
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
