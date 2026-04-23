#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    int ans=-1;
    for(int i=0;i<=30;i++){
        for(int j=0;j<=30;j++){
            int x=((1<<i)+(1<<j));
            if(x<n && (x&n)>0 && x>(x&n)){
                ans=x;
                break;
            }
        }
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