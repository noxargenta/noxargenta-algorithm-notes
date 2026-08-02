#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    string s;
    cin >> s;
    bool o1=0,o2=0;
    for(auto x:s){
        if(x-'A'>=0  && x-'A'<26){
            o1=1;
        }else {
            o2=1;
        }
    }
    if(o1+o2==1){
        cout << "Yes\n";
    }else {
        cout << "No\n";
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