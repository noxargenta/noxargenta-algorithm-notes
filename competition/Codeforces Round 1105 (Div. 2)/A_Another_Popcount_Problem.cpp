#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n,k;
    cin >>n >> k;
    ll cnt=0;
    ll val=1;
    while(cnt < n){
        val*=2;
        //cur表示当前最多选的个数
        ll cur=min(k,n/val);
        
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