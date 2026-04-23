#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    string s;
    cin >> s;
    int ans=0;
    string s2="matiji";
    int ok=0;
    for(int i=0;i<=(int)s.length()-6;i++){
        ok=0;
        if(s[i]=='m'){
            ok=1;
            
            for(int j=0;j<=5;j++){
                if(s[i+j]!=s2[j]){
                    ok=0;
                    break;
                }
                //cout << j << endl;
            // }
            // if(j!=6){
            //     ok=0;
            }
            if(ok==1){
                ans++;
            }            
        }
    }
    cout << ans << endl;
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