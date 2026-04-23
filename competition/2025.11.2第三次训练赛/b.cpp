#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    string n;
    cin >> n;
    int num1=0,num2=0;
    for(int i=0;i<3;i++){
        num1 += (n[i]-'0'); 
        num2 += (n[5-i]-'0');
    }
    if(num1==num2){
        cout << "YES\n";
    }else {
        cout << "NO\n";
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