#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x=0,y=0;
    for(int i=0;i<n;i++){
        if(s[i]=='L'){
            x--;
        }else if(s[i]=='R'){
            x++;
        }else if(s[i]=='U'){
            y++;
        }else if(s[i]=='D'){
            y--;
        }
        if(x==1 && y==1){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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