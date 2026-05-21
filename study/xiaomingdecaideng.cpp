#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m;
    cin >> n >> m ;
    vector<int> a(n+2,0);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<int> b(n+2,0);
    for(int i=1;i<=n;i++){
        b[i]=a[i]-a[i-1];
    }
    while(m--){
        int l,r,x;
        cin >> l >> r >> x;
        b[l]+=x;
        b[r+1]-=x;
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        int x=b[i];
        sum+=x;
        cout << max(sum,(int)0) << ' ';
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