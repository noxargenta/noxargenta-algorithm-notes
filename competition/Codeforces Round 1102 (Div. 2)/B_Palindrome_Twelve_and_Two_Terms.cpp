#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int rev(int p,bool odd){
    string s=to_string(p);
    string s2=s;
    reverse(s2.begin(),s2.end());
    if(odd){
        return stoll(s+s2.substr(1));
    }else {
        return stoll(s+s2);
    }
}
void solve() {
    int n;
    cin >> n;
    
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