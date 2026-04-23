#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    string s;
    cin >> s;
    for(int i=0;i<3;i++){
        switch (i)
        {
        case 0:
            if(s[i]!= 'Y' && s[i]!= 'y'){
                cout << "NO\n";
                return;
            }
        case 1:
            if(s[i]!= 'E' && s[i]!= 'e'){
                cout << "NO\n";
                return;
            }
            
        case 2:
            if(s[i]!= 'S' && s[i]!= 's'){
                cout << "NO\n";
                return;
            }
            
        }
    }
    cout << "YES\n";
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