#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n,k;
    cin >> n >> k;
    vector<array<int,2>> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i][0] >> a[i][1];
    }
    sort(a.begin(),a.end(),greater<array<int,2>>{});
    i64 sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i][1];
        if(sum>k){
            cout << a[i][0]+1;
            return;
        }
    }
    cout << 1;
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 _ = 1;
    // cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}