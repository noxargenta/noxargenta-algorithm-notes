#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int fa[10010],c,d,a,b;
int find(int x){
    if(fa[x]==x){
        return x;
    }else {
        return fa[x]=find(fa[x]);
    }
}
void hb(int x,int y){
    fa[find(y)]=find(x);
}
void solve() {
    int n,m,p;
    cin >> n >> m >> p;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        cin >> c >> d;
        hb(c,d);
    }
    for(int i=1;i<=p;i++){
        cin >> a >> b;
        if(find(a)==find(b)){
            cout << "Yes\n";
        }else{
            cout << "No\n";
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
