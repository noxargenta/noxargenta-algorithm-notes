#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int h,w;
    cin >> h >> w;
    int a[h][w];
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            cin >> a[i][j];
        }
    }
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            if (a[i][j]==0){
                cout << ".";
            } else {
                char c='A'+a[i][j]-1;
                cout << c;
            }
        }
        if (i!=h-1){
            cout << endl;
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