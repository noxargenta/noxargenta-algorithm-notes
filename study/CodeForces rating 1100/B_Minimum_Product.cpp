#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll a,b,x,y,n;
    cin >> a >> b >> x >> y >> n;
    ll sum=(a-x)+(b-y);
    if(sum<=n){
        cout << x *y <<endl;
    }else {
        while(n!=0){
            ll val1=max(a-x,b-y);
            ll val=min(n,val1);
            n-=val;
            if(val1==(a-x)){
                a-=val;
            }else {
                b-=val;
            }
        }
        cout << a*b <<endl;
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
