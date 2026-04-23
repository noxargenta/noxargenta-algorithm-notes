#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    string s;   
    cin >> std::ws;
    getline (cin,s);
    int num=0;
    for(int i=0;i<s.size();i++){
        if((s[i]>='a' && s[i] <='z') || (s[i]>='A' && s[i] <='Z') || isdigit(s[i])){
            num++;
    }
    
}
cout << num;
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