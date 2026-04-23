#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int r,c;
    cin >> r >> c;
    vector<string> a(r);
    for (int i=0; i<r; i++){
        cin >> a[i];
    }
    vector<string> b = a;
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            char temp = a[i][j];
            if (temp >= '1' && temp <= '9'){
                int power = temp - '0';
                for (int x=0; x<r; x++){
                    for (int y=0; y<c; y++){
                        if (abs(i-x) + abs(j-y) <= power){
                            b[x][y] = '.';
                        }
                    }
                }
            }
        }
    }
    for (int i=0; i<r; i++){
        cout << b[i] << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}