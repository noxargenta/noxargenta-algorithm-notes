// https://qoj.ac/contest/4616/problem/23665
/*
4
3
1 2 3
2 2 3
3
0 0 0
2 3 3
3
3 3 2
2 3 3
4
10000 10000 10000 10000
2 3 3 3

*/
/*
YES
NO
YES
YES
*/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    map<ll,ll> cnta,cntb;
    for(ll i=1;i<=n;i++){
        cin >> a[i];
        cnta[a[i]]++;
    }
    for(ll i=1;i<=n;i++){
        cin >> b[i];
        cntb[b[i]]++;
    }
    vector<pair<ll,ll>> pa;
    for(auto [v,c] : cntb){
        pa.push_back({v,c});

    }
    sort(pa.begin(),pa.end(),[&](const auto& x,const auto &y){
        return x.first-x.second < y.first - y.second;
    });
    ll k=0;

    for(auto [x,y] : pa){
        if(k+y >= x){
            k+=y;

        }else if(cnta[x]<y){
            cout << "NO\n";
            return;
        }

    }   
    cout << "YES\n";

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