#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int x,y;
    cin >>x >> y;
    if(y==0){
        if(x>0){
            cout << "1\n";
        }else  {
            cout << "0\n";
        }
        return;
    }
    if(x<y){
        cout << "2\n";
    }else if(y>=2&&y<=x-2){
        cout << "3\n";
    }else {
        cout << "-1\n";
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