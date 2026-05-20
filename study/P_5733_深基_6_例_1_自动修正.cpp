#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    string s;
    cin  >> s;
    for(int i=0;i<s.length();i++){
        if(s[i]<='z' && s[i] >= 'a'){
            s[i]=s[i]+'A'-'a';
        }
    }
    cout << s << endl;
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