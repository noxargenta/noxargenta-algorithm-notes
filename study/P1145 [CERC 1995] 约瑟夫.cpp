#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
ll k;
bool check(ll m){
    ll cur=0;
    for(ll i=0;i<k;i++){
        ll remain=2*k-i;//剩余人数
        cur=(cur + m - 1)%remain;
        
    }
}
void solve() {
    
    cin >> k;
    for(ll i=1;;i++){
        ll t1=i * (k+1);
        ll t2=i*(k+1) +1;
        if(check(t1)){
            cout << t1 <<endl;
            return;
        }
        if(check(t2)){
            cout << t2 <<endl;
            return;
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