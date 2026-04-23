#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> a(m+1),b(m+1);
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        a[x]=y;
        a[y]=x;
    }
    int res=0;
    for(int i=1;i<=n;i++){
        if(a[i]==i){
            res++;
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