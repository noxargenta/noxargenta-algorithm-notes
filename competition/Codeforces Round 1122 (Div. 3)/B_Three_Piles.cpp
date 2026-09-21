#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll a,b,c;
    cin >> a >> b >> c;
    if(a<b){
        ll val=abs(a+c-b);
        ll val2=abs(a-b);
        cout << max(val,val2) <<endl;
    }else {
        cout << a+c-b <<endl;
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