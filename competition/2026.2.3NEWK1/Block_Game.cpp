#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n+1);
    int x=-0x7f7f7f7f;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(i>=2){
            x=max(x,a[i-1]+a[i]);
        }
    }
    x=max(a[1]+k,x);
    x=max(a[n]+a[1],x);
    cout << x << endl;
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