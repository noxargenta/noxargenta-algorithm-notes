#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
bool check(ll x){
    while(x){
        ll xx=x%10;
        x/=10;
        if(xx!=4 && xx!=7){
            return 0;
        }
    }
    return 1;
}
void solve() {
    
    for(ll i=1;i<=1000;i++){
        if(check(i)==1){
            cout << i <<",";
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