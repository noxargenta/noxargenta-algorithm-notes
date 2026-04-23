#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >> n;
    int s[n][n];
    int s2[n+2][n+2];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char temp;
            cin >>temp;
            s[i][j]=temp-'0';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            s2[i+1][j+1]=s[i][j];
        }
    }
    for(int j=2;j<n+2;j++){
        s2[1][j]=s[0][j-2];
    }
    for(int j=0;j<n;j++){
        s2[n-1][j]=s[0][j];
    }
    for(int i=0;i<n;i++){
        s2[i][1]=s[i][0];
    }
    for(int i=2;i<n+2;i++){
        s2[i][n]=s[i-1][n-1];
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            cout << s2[i][j];
        }
        cout << endl;
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