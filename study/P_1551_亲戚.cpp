#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
const int N=5005;
int fa[N];
int find(int x){
    return fa[x]==x ? x : fa[x]=find(fa[x]);
}
void solve() {
    int n,m,p;
    cin >> n >> m >> p;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    while(m--){
        int x,y;
        cin >> x >> y;
        fa[find(x)]=find(y);
    }
    while(p--){
        int x,y;
        cin >> x >> y;

        if(find(x)==find(y)){
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