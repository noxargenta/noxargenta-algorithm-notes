#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if((i%2!=0 && j%2!=0)||(i%2==0 && j%2==0)){
                cout << "/";
            }
            if((i%2!=0 && j%2==0) ||(i%2==0 && j%2!=0)){
                cout << "\\";
            }
            if(j==m){
                cout << endl;
            }    
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