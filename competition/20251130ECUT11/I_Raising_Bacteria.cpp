#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void solve() {
    int n;
    int ans=0;
    cin >> n;
    while(n>1){
        if(n%2==0){
            n/=2;
            if(n==1){
                break;
            }
        }else {
            ans++;
            n--;
            n/=2;
            if(n==1){
                break;
            }
        }
    }
    ans++;
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