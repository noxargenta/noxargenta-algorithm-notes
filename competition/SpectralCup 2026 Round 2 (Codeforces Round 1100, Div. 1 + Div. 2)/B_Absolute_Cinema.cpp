#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<int> b(n+1);
    int maxxa=0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        maxxa=max(a[i],maxxa);
    }
    int sum=maxxa;
    for(int i=1;i<=n;i++){
        cin >> b[i];
        if(a[i]!=maxxa && a[i]>b[i]){
            b[i]=a[i];
        }
        sum+=b[i];
    }

    cout << sum << endl;
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