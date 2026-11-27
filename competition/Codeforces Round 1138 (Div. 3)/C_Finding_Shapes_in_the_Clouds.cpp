#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    bool ok=0;
    if(n%2!=0){
        cout << "NO\n";
        return;
    }
    for(ll i=0;i<s.length()-1;i++){
        if(s[i]==s[i+1]){
            ok=1;
        }
    }
    if(ok==1){
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
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}