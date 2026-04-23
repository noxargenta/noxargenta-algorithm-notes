#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >>n;
    vector<int> a(n+1,0),cnt(n+1);
    int ans=1;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        cnt[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        cnt[a[i]]--;
        int s=n-i-cnt[a[i]];
        ans+=s;
        while(i<n&&a[i+1]==a[i]){
            cnt[a[i]]--;
            i++;
        }
    }
    cout << ans <<endl;


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