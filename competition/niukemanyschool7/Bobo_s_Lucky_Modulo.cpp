#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    int n;
    cin >> n;
    ll ans=0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            // if(i==j){
            //     continue;
            // }
            if((i%j)+1==i%(j+1)){
                ans++;
            }
        }
    }
    cout << "n:" << n <<endl;
    cout << "asn:" <<ans <<endl;
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    //cin >> _;
    while(1) {
        solve();
    }
    return 0;
}