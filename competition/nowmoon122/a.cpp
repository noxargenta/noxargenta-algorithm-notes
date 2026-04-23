#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    vector<int> a(6);
    vector<int> b(6);
    for(int i=0;i<6;i++){
        cin >>a[i];
    } 
    for(int i=0;i<6;i++){
        cin >>b[i];
    }
    int x,y;
    cin >> x >> y;
    int sum=0;
    for(int i=0;i<6;i++){
        if(a[i]==y){
            sum ++;
        }
    }
    for(int i=0;i<6;i++){
        if(b[i]==y){
            sum ++;
        }
    }
    if(sum < x){
        cout << "win\n";
    }else {
        cout << "lose\n";
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