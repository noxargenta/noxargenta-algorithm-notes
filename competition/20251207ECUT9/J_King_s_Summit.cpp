#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
    }
    int a1=0;
    int b1=0;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ans1=(a[n-1]+a[0])/2;
    int ans2=(b[n-1]+b[0])/2;
    a1=a[n-1]-ans1;
    b1=b[n-1]-ans2;
    cout << max(a1,b1) << endl;
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