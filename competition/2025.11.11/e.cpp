#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int n;
    cin >> n;
    int minx=1e9,maxx=-1e9;
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        minx=min(minx,t);
        maxx=max(maxx,t);
    }
    int n2;
    cin >> n2;
    if(n2>=minx && n2<=maxx){
        cout << "YES\n";
    }else {
        cout << "NO\n";
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