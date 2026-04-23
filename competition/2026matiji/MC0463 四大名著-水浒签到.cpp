#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin  >> n;
    //int a[n+1];
    int x=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        int val ;
        cin >> val;
        if(x<2){
            ans+=val;
        }  else {
            ans-=val;
        }
        x=(x+1)%4;
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