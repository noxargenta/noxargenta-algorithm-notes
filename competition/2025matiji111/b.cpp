#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void solve(){
    int n;
    cin >> n;

    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int ans=0;
    // int f[n+1];
    // int g[n+1];
    int maxx=-1;
    int minn=100006;
    for(int i=1;i<=n;i++){
        maxx=max(maxx,a[i]);
        minn=min(minn,a[i]);
        ans+=maxx+minn;
    }
    cout << ans << endl;
}   
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _=1;
    //cin  >> _;
    while(_--){
        solve();
    }
}