#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll p;
    cin >> p;
    for(ll x=sqrt(p) + 1;;x++){
        ll q=x*x-p;
        ll x1=x%q;
        ll x2=x%p;
        if(x1>=1 && x2 >=1 && q!=0 && p!=0 && x1<q && x2<p){
            cout << x1<<" " << x2 <<" "<< q<<" " <<endl;
            return;
        }
    }
    cout << "Impossible\n";
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