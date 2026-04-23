#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int ans=0;
    int num=0;
    sort(a.begin(),a.end());
    for(int i=1;i<=n && num!=k;i++){
        while(a[i]>0){
            if(num==k){
                break;
            }
            ans+=a[i];
            num++;
            a[i]--;
        }
    }
    cout << ans << endl;
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