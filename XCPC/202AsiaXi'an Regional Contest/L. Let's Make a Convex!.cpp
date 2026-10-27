#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a.begin()+1,a.end(),greater<ll>());
    ll maxx=a[1];
    ll val=0;
    for(ll i=1;i<=n;i++){
        if(i!=1){
            val+=a[i];
        }
        if(val > maxx){
            cout << val + maxx << " ";
        }else {
            cout << 0 << " ";
        }

    }
    cout << endl;
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