#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
mt19937_64 rng (chrono::steady_clock::now().time_since_epoch().count());
void solve() {
    ll m=100;
    ll i=1;

    while(m--){
        cout << "i:" << i <<" ";    
        i++;
        cout << rng() <<endl;

    }

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