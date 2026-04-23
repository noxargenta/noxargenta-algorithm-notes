#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int p[2002];
int find(int x){
    if(x!=p[x]){
        p[x]=find(p[x]);
    }
    return p[x];
}
void merge(int x ,int y){
    p[find(x)]=find(y);
}
void solve() {
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=2*n;i++){
        p[i]=i;
    }
    for(int i=1;i<=m;i++){
        char c;
        int x,y;
        cin >> c >> x >> y;
        if(c=='E'){
            merge(x+n,y);
            merge(y+n,x);
        }else {
            merge(x,y);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(p[i]==i){
            ans++;
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