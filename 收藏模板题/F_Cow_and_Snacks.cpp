#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
#define N 100005
int f[N];
int find(int x){
    return f[x]==x? x:f[x]=find(f[x]);
}
void solve() {
    int n,k;
    cin >> n >> k;
    int ans=0;
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    for(int i=1;i<=k;i++){
        int v,u;
        cin >> v >> u;
        int fv=find(v),fu=find(u);
        if(fv==fu){
            ans++;
        }else {
            f[fv]=fu;
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