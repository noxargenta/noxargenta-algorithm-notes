#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll l,a,b;
    cin >> l >> a >> b;
    vector<pair<ll,ll>> bb(l+10,{0,0} );
    
    for(ll i=0;bb[i].first!=1;i= (i + a)% l  ){
        bb[i].first=1;
    }
    for(ll i=0;bb[i].second!=1;i= (i + b)% l  ){
        bb[i].second=1;
    }
    ll cnt=0;
    for(ll i=0;i<l;i++){
        if(bb[i].first==1 && bb[i].second==1){
            cnt++;
        }
    }
    cout << cnt << endl;

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
/*5
6 2 3
10 4 7
5 1 1
4 10 21
15 20 8
*/

/*1
5
5
2
3*/