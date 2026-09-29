#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n,m;
    cin >> n >> m;
    if(n>=m){
        cout << n-m <<endl;
        return;

    }
    ll ans=0;
    while(n!=m){
        if(m%2!=0){
            m--;
            ans++;
        }else {
            m/=2;
        }
    }
    cout <<ans <<endl;




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