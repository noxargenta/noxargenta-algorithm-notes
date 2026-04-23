#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    int a[n+1];
    map<int,int> m;
    
    for(int i=1;i<=n;i++){
        cin >> a[i];
        m[a[i]]++;
    
    }
    for(int i=1;i<=n;i++){
        cout << m[a[i]]-1 << " ";
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