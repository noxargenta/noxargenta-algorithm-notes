#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
bool isPrime(int x){
    if(x<2){
        return 0;
    }
    for(int i=2;i*i<=x;i++){
        if(x%2==0){
            return 0;
        }
    }
    return 1;
}
void solve() {
    int L;
    cin >> L;
    
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