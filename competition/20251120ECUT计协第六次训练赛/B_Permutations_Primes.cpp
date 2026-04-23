#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >> n;
    if(n==1){
        cout << "1\n";
        return;
    }
    if(n==2){
        cout << "2 1\n";
        return;
    }
    int x=4;
    cout << "2 ";
    for(int i=2;i<=n/2;i++){
        cout << x << " ";
        x++;
    }
    cout << "1 ";
    for(int i=n/2+2;i<n;i++){
        cout << x << " ";
        x++;
    }
    cout << "3\n";
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