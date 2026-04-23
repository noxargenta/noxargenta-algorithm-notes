#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
const int MOD = 998244353;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<int> b(n+1);
    int ma=0x7f7f7f7f;
    int mb=0x7f7f7f7f;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        ma=min(ma,a[i]);
    }
    for(int i=1;i<=n;i++){
        cin >> b[i];
        mb=min(mb,b[i]);
    }
    int ans=1;
    if(ma>mb){
        for(int i=1;i<=n;i++){
            ans = (ans * i) % MOD;
        }
    }else {
        int x=0;
        for(int i=1;i<=n;i++){
            if(a[i]>mb){
                x++;
            }
        }
        for (int i = 1; i <= x; i++) {
            ans = (ans * i) % MOD;
        }
        for (int i = 1; i <= n-x; i++) {
            ans = (ans * i) % MOD;
        }
    }
    cout << ans  << endl;
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