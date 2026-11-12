#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    map<ll,ll> cnt;
    vector<ll> a,b;
    for(ll i=1;i<=1000;i++){
        a.push_back(i);
        b.push_back(i+1);
    }
    for(auto i : a ){
        for(auto j : b){
            if(cnt[i*j]==1){
                cout << "NO\n";
            }
        }
    }
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