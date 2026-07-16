#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m;
    cin >> n  >> m;
    vector<int> a(n+1,0);
    for(int j=1;j<=m;j++){
        int l,r;
        cin >> l >> r;
        for(int i=l;i<=r;i++){
            int inc=min(i-l+1,r-i+1);
            a[i]+=inc;
            for()
        }
    }
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}