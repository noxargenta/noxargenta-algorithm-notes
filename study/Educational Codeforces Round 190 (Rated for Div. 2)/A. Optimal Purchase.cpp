#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,a,b;
    cin >> n >> a >>b;
    if(3*a<=b){
        cout << n*a << endl;
    }else {
        int ans=0;
        ans+=n/3*b;
        n%=3;
        ans+=min(n*a,b);
        cout << ans << endl;
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