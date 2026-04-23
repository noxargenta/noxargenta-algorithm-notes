#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
bool chck(int x){
    if(x%2==0){
        return false;
    }
    if(int i=3;i<sqrt(x);i+=2){
        if(x%i==0){
            return false;
        }
    }
    return true;
}
void solve() {
    int x;
    cin >> x;
    int c=0;
    if(chck(x)){
        for(int i=x/2;;i--){
            
        }
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