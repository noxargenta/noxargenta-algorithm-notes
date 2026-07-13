#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int f(int x){
    if(!x) return 0;
    return __builtin_popcountll(x) + 63 - __builtin_clzll(x);
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int ans=LLONG_MAX;
    for(int v=0;(1<<v)<=1e5;v++){
        int cur=0,step=(1LL<<v);
        for(int i=1;i<=n;i++){
            int mn=LLONG_MAX;
            int x=((a[i]+step-1)/step)*step;
            if(x==0) x=step;
            for(int j=x;j-x<=50;j+=step){
                mn=min(mn,j-a[i]+f(j));
            }
            cur+=mn;
        }
        cur-=(n-1)*v;
        ans=min(ans,cur);
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