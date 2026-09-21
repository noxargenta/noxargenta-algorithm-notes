#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
ll a[]={60,90,108,120,135,140,144,150,156,160,
162,165,168,170,171,172,174,175,176,177,178,179};
// void solve() {
//     for(ll i=1;i<=100000;i++){
//         double j=((i-3+1)*180*1.0/i);
//         if(abs(j-round(j))<1e-9){
//             cout << j << ",";
//         }
        
//     }
// }

void solve() {
    ll n;
    cin >> n;
    for(auto x :a){
        if(x==n){
            cout << "YES\n";
            return;
        }

    }
    cout << "NO\n";
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