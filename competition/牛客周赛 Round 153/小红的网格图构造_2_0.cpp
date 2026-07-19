#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    int nn=n/2,mm=m/2;
    if(nn*mm>k){
        cout << "No\n";
        return;
    }
    vector<string> a(n,string('0',m));
    
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