#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int n,k;
    cin >> n>> k;
    vector<int> a(3 * n + 100, 0);
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        a[x]++;
    }
    int ans=0,sum=0,now=0;
    for(int i=1;i<=3*n;i++){
        sum+=a[i]-1;
        now++;
        if(sum<k){
            sum=0;
            now=0;
        }
        ans=max(ans,now);
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