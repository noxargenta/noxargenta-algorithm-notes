#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll n0=0;
    ll n1=0;
    for(auto x : s){
        if(x=='0'){
            n0++;
        }else n1++;

    }
    if(abs(n1-n0)>=3){
        cout << -1<<endl;
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