#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
const int N = 2e5+1;
int fa[N];
int n,m;
int find (int x){
    if(fa[x] == x){
        return x;
    }else {
        return fa[x]=find(fa[x]);
    }
}
void solve() {
    int n,m;
    cin >> n >> m;
    for(int i=1; i<= n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        int op,x,y;
        cin >> op >> x >> y;
        if(op == 1){
            x= find(x),y=find(y);
            fa[x]=y;
        }else {
            x=find(x),y=find(y);
            if(x==y){
                cout << "Y" << endl;
            }else {
                cout << "N" << endl;
            }
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