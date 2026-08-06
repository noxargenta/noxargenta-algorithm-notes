#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
ll isPrime(ll x){
    if(x<=1){
        return 0;
    }
    for(int i=2;i<=x/2;i++){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}
void solve() {
    ll n;
    cin >> n;
    if(isPrime(n-1)){
        if(n-3-1==2 || n==4 || n==3){
            cout << -1 << endl;
        }else {
            for(int i=1;i<=n-4;i++){
                cout << i<<' ';
            }
            
        }

    }else {
        for(int i=1;i<=n;i++){
            cout << i <<  " ";
        }
        cout << endl;
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