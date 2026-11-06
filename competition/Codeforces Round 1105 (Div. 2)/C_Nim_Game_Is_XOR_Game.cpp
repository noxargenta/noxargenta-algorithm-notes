#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n;
    cin >> n;

    ll cnt=0;

    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]!=0){
            cnt++;
        }    
    }
    if(n==1){
        cout << 0 <<endl;
    }else{
        if(cnt>=2){
            cout << cnt << endl;
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