#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    for(ll i=1;i<=1000;i++){
        for(ll j=1;j<=1000;j++){
            for(ll a=1;a<=1000;a++){
                for(ll b=1;b<=1000;b++){
                    if((a==i && b==j) ||(a==j && b==i)){
                        continue;
                    }else if(a*b==i*j){
                        cout << a << "*" << b << "==" << i << "*" << j << endl;
                    }
                }
            }
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