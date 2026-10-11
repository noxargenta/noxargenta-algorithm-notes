#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll l=0,r=1e9;
    while(l<=r){
        ll mid=(l+r)/2;
        cout << "? " << mid << endl; 
        ll x;
        cin >> x;
        if(x==1){
            r=mid-1;
        }else {
            l=mid+1;
        }
        
    }
    cout << "! " << l << endl;
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}