#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >>n;
    string s;
    string s2;
    cin >> s;
    cin >> s2;
    for(int i=0;i<n;i++){
        if(s[i]!=s2[i] && !(s[i]=='0' && s2[i]=='o') && !(s[i]=='o' && s2[i]=='0') && !(s[i]=='1' && s2[i]=='l') && !(s[i]=='l' && s2[i]=='1')){
            cout << "No";
            return;
        }
    }
    cout << "Yes";
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