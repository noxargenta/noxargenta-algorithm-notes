#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int a[4]={1,0,0,1},b[4]={0,1,1,0};
void solve() {
    int n,m;
    cin >> n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i%4<=1){
                cout << a[(j-1)%4] << " ";
            }else {
                cout << b[(j-1)%4]<< " ";
            }
        }
        cout << endl;
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