#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    int x,y;
    int maxx=-0x7f7f7f7f;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(i>1&& i<n){
            maxx=max(maxx,a[i]);
        }
    }
    if(maxx>max(a[1],a[n])){
        cout << maxx*(n-2) + a[1] +a[n] << endl;
    }else {
        cout << max(a[1],a[n]) * n << endl;
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