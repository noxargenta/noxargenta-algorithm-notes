#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    vector<ll> a(3);
    for(ll i=0;i<3;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    if(a[2]>a[0]+a[1]){
        a[2]=a[0]+a[1];
    }
    cout << a[2]-a[0] <<endl;
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