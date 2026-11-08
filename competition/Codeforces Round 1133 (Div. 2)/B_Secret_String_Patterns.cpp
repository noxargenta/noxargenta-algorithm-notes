#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
//#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n;
    cin >> n;
    cout << "? 1 " << n;
    ll x;
    cin >> x;
    if(x==0 || x==n){
        cout << "! NO\n";
        return;
    }   
    cout << "? 1 " << x <<endl;
    ll k;
    cin >> k;
    if(k<x){
        cout << "! YES\n";
    }else {
        cout << "! NO\n";
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