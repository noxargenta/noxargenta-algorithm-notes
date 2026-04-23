#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int last=-1;
    int ans=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            continue;
        }else {
            ans+=(i-last)*(s.length()-i);
            last=i;
        }
    }
    cout << ans << endl;
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