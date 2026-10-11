#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define ll long long
void solve(ll x) {
    if(x==0){
        ll n,m;
        cin >> n >> m;
        vector<vector<ll>> G[]
        ll a[m][2];
        for(ll i=0;i<m;i++){
            for(ll j=0;j<2;j++){
                cin >> a[i][j];
            }
        }
        cout << m <<endl;
        for(ll i=0;i<m;i++){
            for(ll j=0;j<2;j++){
                cout << a[i][j];
            }
            cout << endl;
        }
        for(ll i=1;i<=3;i++){
            ll x;
            cin >> x;

        }
    }

}

signed main(int,char* st[]) {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    ll x=st[1][0]-'0';
    while(_--) {
        solve(x);
    }
    return 0;
}