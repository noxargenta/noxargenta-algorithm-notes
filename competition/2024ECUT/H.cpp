#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        cin >> b[i];
    }
    int ans=0;
    int l=1,r=1;
    int mixx,maxx;
    while(l<=n){
        mixx=0x7f7f7f7f;
        maxx=-0x7f7f7f7f;
        
        l++;
        r=l;
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