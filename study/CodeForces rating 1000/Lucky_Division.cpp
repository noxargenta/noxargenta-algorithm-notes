#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
ll aa[]={4,7,44,47,74,77,444,447,474,477,744,747,774,777};
void solve() {
    string s;
    cin >>s;
    ll a=stoll(s);
    bool ok=1;
    for(auto x:s){
        if(x!='4' && x!='7'){
            ok=0;
        }
    }
    for(auto x : aa){
        if(x>a){
            break;
        }
        if(a%x==0){
            ok=1;
            break;
        }
    }
    if(ok){
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