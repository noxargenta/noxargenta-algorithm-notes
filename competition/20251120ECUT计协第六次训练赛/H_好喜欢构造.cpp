#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int n;
    cin >> n;
    if(n%2==0){
        cout << n*n/2 << endl;
        for(int i=1;i<=n;i++){
            if(i%2!=0){
                for(int j=1;j<=n/2;j++){
                    cout << "C.";
                }
                cout << endl;
            }else {
                for(int j=1;j<=n/2;j++){
                    cout << ".C";
                }
                cout << endl;
            }
        }
    }else {
        cout << (n*n+1)/2 << endl;
        for(int i=1;i<=n;i++){
            if(i%2!=0){
                for(int j=1;j<=n/2;j++){
                    cout << "C.";
                }
                cout << "C";
                cout << endl;
            }else {
                for(int j=1;j<=n/2;j++){
                    cout << ".C";
                }
                cout << ".";
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