#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(2*n+99);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        a[n+i]=a[i];
    }
    int l=1,r=1;
    int cnt=0;
    int ans=0;
    while(r<2*n){
        r++;
        if(abs(a[r]-a[r-1])>k){
            cnt++;
        }
        while(cnt>m){
            l++;
            if(abs(a[l]-a[l-1])>k){
                cnt--;
            }
        }
        ans=max(ans,r-l+1);
    }
    if(ans>n){
        cout << n << endl;
    }else {
        cout << ans << endl;
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