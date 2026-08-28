#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    string s;
    cin >> s;
    ll l=0;
    ll r=0;
    for(ll i=0;i<s.length();i++){
        if(s[i]=='('){
            l++;
        }else if(s[i]==')'){
            if(l==0){
                cout << "NO\n";
                return;
            }
            l--;
        }

    }
    if()
    cout << "YES\n";
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