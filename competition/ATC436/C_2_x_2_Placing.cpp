#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m;
    cin >> n>>m;
    set <pair<int ,int>> oc;
    int ans=0;
    for(int i=0;i<m;i++){
        int r,c;
        cin >> r >> c;
        bool ok=0;
        if(oc.count({r,c})||oc.count({r+1,c})||oc.count({r,c+1})||
            oc.count({r+1,c+1})){
                ok=1;
        }
        if(ok==0){
            ans++;
            oc.insert({r,c});
            oc.insert({r+1,c});
            oc.insert({r,c+1});
            oc.insert({r+1,c+1});
        }        
    }
    cout << ans << endl;
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