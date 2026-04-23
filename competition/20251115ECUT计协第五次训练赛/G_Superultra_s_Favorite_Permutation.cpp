#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int n;
    cin >> n;
    if(n<=4){
        cout << "-1" <<  endl;
    } else {
        for(int i=1;i<=n ;i+=2){
            if(i!=5){
                cout << i << " ";
            }
            
        }
        cout << "5 4 ";
        for(int i=2;i<=n ;i+=2){
            
            if(i!=4){
                cout << i << " ";
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