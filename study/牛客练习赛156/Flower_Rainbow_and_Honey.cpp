#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    string s1,s2;
    cin >> s1 >> s2;
    ll l=0,r=0;

    for(ll i=0;i<2;i++){
        if(s1[i]=='L'){
            l++;
        }else {
            r++;
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