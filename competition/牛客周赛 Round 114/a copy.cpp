#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int a1,a2,a3;
    for(int i=0;i<3;i++){
    int t=0;
    cin >>t;           
        if(t==1){
            a1=i+1;
        }else if(t==2){
            a2=i+1;
        }else if(t==3){
            a3=i+1;
        }
    }                           
    cout << a1 <<" " << a2 << " " << a3;
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