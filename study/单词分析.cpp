#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    string s;
    cin >> s;
    int a[26]={0};
    int maxx=0;
    for(int i=0;i<s.length();i++){
        a[s[i]-'a']++;
        maxx=max(a[s[i]-'a'],maxx);
    }
    for(int i=0;i<26;i++){
        if(a[i]==maxx){
            cout << (char)('a'+i) << endl << maxx << endl;
            return ;
        }
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