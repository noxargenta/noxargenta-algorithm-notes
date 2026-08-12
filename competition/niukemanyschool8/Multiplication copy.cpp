#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll a,b,c;cin >>a >> b >> c;
    string x=string(a,'3');
    string y="3"+string(b-1,'0');
    string x1=x+string(a+b,'9');
    string x2=x+string(a+b,'0');
    string y1=y+string(a+b,'9');
    string y2=y+string(a+b,'0');
    cout << x1<<" "<<y1<<" "<< x2 << " " << y2 <<endl;
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