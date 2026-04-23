#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n,k;
    cin >> n >> k;
    int m=n/k;
    string a[n];
    int b[m][m];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            if(x%k==0 && y%k==0){///////////////////////
                b[x/k][y/k]=a[x][y]-'0';
            }
        }
    }
    for(int x=0;x<m;x++){
        for(int y=0;y<m;y++){
            cout << b[x][y];
            if(y==m-1){
                cout << endl;
        }
    }
}
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}