#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    string s;
    cin >> s;
    string s2;
    for(auto x:s){
        if(x=='D' ){
            if(!s2.empty())s2.pop_back();
        }else {
            s2.push_back(x);
        }
    }
    if(s2.empty()){
        cout << "!!!!\n";
    }else {
        cout << s2 << endl; 
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