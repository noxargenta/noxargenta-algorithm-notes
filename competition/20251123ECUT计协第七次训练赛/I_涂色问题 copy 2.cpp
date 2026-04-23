#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        if(s[i-1]=='B'){
            a[i]=0;
        }else {
            a[i]=1;
        }
    }
    vector<int> b(n+1);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    int ans=200005;
    for(int l=0,r=k;r<=n;l++,r++){
        ans=min(b[r]-b[l],ans);
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