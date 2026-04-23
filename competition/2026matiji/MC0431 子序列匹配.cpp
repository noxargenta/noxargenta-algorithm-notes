#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
string s;
void solve() {
    string s2;
    cin >> s2;
    int j=0,k=0;
    for(;j<s2.length() && k<s.length();){
        if(s[k]==s2[j]){
            j++;
            k++;
        }else{
            k++;
        }
        
    }
    if(j==s2.length()){
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }
    
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}