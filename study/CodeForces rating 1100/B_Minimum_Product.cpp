#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll a,b,x,y,n;
    cin >> a >> b >> x >> y >> n;
    if(a>b){
        swap(a,b);
        swap(x,y);
    }
    ll val=min(n,a-x);
    n-=val;
    a-=val;
    if(n==0){
        cout << a * b <<endl;
        return;
    }
    val=min(n,b-y);
    n-=val;
    b-=val;
    // cout <<  "a:" <<a <<endl;
    // cout << "b:" << b << endl;
    cout << a*b <<endl;
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
