#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int t,n,l,r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int ans=0;
    i64 sum=0;
    int j=0;
    for(int i=0;i<n;i++){
        sum +=a[i];
        while(sum>r && j<=i){
            sum -= a[j];
            j++;
        }
        if(sum >= l && sum <= r){
            ans++;
            sum =0;
            j=i+1;
        }
    }
    cout << ans << endl;
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