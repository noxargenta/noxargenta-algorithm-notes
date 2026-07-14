#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m;
    cin >>n >> m;
    vector<int> a(n+1);
    vector<bool> b(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=m;i++){
        int x;
        cin >> x;
        b[x]=1;
    }
    int dp0=0;//后缀
    int dp1=-LLONG_MAX;
    for(int i=n;i>0;i--){
        int n0,n1;//下一个更新后缀
        if(b[i]==1){
            n0=max(dp0,dp1) + a[]
        }
    }

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