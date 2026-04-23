#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int n,k,m,x[550],maxx;
void solve() {
    cin >> n >> k >> x[1];
    maxx=x[1];
    for(int i=2;i<=k;i++){
        cin >> x[i];
        maxx=max(maxx ,(x[i]-x[i-1])/2+1);
    }
    maxx=max(maxx,n-x[k]+1);
    cout << maxx << endl;
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