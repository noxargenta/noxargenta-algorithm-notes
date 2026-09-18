#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    string s;
    cin >> s;
    ll lx=0;
    string s2="hello";
    ll r=0;
    for(ll i=0;i<s.length()&& r<s2.length();i++){
        if(s[i]==s2[r]){
            r++;
            continue;
        }
    }
    if(r==s2.length()){
        cout << "YES\n";
    }else {
        cout << "NO\n";
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