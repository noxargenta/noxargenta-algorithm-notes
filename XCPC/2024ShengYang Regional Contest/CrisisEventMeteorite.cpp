#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    vector<pair<ll,string>> a(8);
    for(ll i=0;i<8;i++){
        string s;
        ll x;
        cin >> s >> x;
        a[i].first=x;
        a[i].second=s;

    }
    sort(a.begin(),a.end());
    cout << a[7].second <<  " beats " << a[6].second <<endl;
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