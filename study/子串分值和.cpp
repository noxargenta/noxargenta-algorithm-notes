#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    string s;
    cin >> s;
    s=" " + s;
    int last[26];
    int sum=0;
    fill(last,last+26,0);
    for(int i=1;i<s.length();i++){
        sum+=(i-last[s[i]-'a'])*(s.length()-1-i);
        last[s[i]-'a']=i;
    }
    cout << sum << endl;
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