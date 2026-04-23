#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<i64> b(n,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
        b[i]+=a[i];
        if(i>=1){
            b[i]+=b[i-1];
        }
    }
    i64 maxnum = -10000;
    i64 minb = 0;
    for(int i=0;i<n;i++){
        maxnum=max(maxnum,b[i]-minb);
        minb=min(minb,b[i]);
    }
    cout << maxnum;
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
