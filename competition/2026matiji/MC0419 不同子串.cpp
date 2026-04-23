#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    string s;
    cin >> s;
    set<string> se;
    for(int i=0;i<s.length();i++){
        for(int j=1;j<s.length()-i+1;j++){
            se.insert(s.substr(i,j));
        }
    }
    cout << se.size() << endl;
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