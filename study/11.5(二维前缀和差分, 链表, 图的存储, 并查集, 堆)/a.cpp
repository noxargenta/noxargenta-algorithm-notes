#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n,p;
    cin >> n >> p;
    vector<i64> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<i64> b(n+2,0);
    for(int i=1;i<=p;i++){
        int x,y,z;
        cin >> x >> y >> z;
        b[x]+=z;
        b[y+1]-=z;
    }
    i64 min = -1;
    i64 current = 0;
    for(int i=1;i<=n;i++){
        current+=b[i];
        a[i]+=current;
        if(min == -1 || min > a[i]){
            min = a[i];
        }
    }
    cout << min;
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
