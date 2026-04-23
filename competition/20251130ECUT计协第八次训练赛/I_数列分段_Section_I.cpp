#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i=1;i<n+1;i++){
        cin >> a[i];
    }
    int cu=0;
    int count=0;
    for(int i=1;i<=n;i++){
        cu+=a[i];
        if(cu>m){
            cu=0;
            cu+=a[i];
            count++;
        }
    }
    count++;
    cout << count << endl;
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    //cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}