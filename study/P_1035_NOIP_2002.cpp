#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int k;
    cin >> k;
    double ans=0;
    int nn=0;
    for(int i=1;ans-k<=0;i++){
        ans+=1.0/i;
        nn=i;
    }
    cout << nn << endl;
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