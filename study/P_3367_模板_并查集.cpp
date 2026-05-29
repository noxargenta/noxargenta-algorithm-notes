#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
const int N=2*1e5+2;
int M;
int f[N];
int fa(int x){
    return x==f[x] ? x : fa(f[x]);
}   
void solve() {
    int n,m;
    cin >> n  >> m;
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    while(m--){
        int z,x,y;
        cin >> z >> x >>y;
        if(z==1){
            int xf=fa(x);
            int yf=fa(y);
            f[xf]=yf;
            f[yf]=yf;
        }else {
            if(f[x]==f[y])cout << "Y\n";
            else cout << "N\n";
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