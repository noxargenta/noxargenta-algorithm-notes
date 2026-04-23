#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,q,s;
    cin >> n >> q>>s;
    vector<int> a(n+2,0);
    a[1]=s;
    for(int i=2;i<=n+1;i++){
        int x;
        cin >> x;
        a[i]+=x;
        a[i]+=a[i-1];
    }
    while(q--){
        int x,y;
        cin >> x >> y;
        cout << a[x]+y-1<< endl;
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