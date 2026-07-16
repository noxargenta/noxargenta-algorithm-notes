#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,k;
    cin >> n >> k;
    string s;
    cin  >> s;
    if(2*k> n ){
        cout << -1 << endl;
    }else {
        int fl=0;
        for(int i=0;i<k;i++){
            if(s[i]=='L'){
                fl++;
            }
        }
        for(int i=n-k;i<n;i++){
            if(s[i]=='R'){
                fl++;
            }
        }
        cout << fl <<endl;
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