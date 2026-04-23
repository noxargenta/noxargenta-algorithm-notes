#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    string s;
    cin >> s;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        if(s[i]=='q'){
            s[i]='p';
        }else if(s[i]=='p'){
            s[i]='q';
        }
    }
    cout << s << endl;
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