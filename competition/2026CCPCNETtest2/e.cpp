#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define ll long long
void solve(ll x) {
    if(x==0){
        ll n;
        cin >> n;
        vector<ll> a(n+1,0);
        for(ll i=1;i<=n;i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        cout << n << endl;
        cout.flush();
        for(ll i=1;i<=n;i++){
            cout << a[i] << " ";
            cout.flush();
        }
        cout << endl;
        cout.flush();
        ll y;
        cin >> y;
        cout << y <<endl;
        cout.flush();
    }else {
        ll n;
        cin >> n;
        vector<ll> a(n+1,0);
        for(ll i=1;i<=n;i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        ll m;
        cin >> m;
        vector<ll> b(m+1,0);
        for(ll i=1;i<=m;i++){
            cin >> b[i];
        }
        sort(b.begin(),b.end());
        if(a==b){
            cout << 1 << endl;
            cout.flush();
        }else {
            cout << 0 << endl;
            cout.flush();
        }
    }
}

signed main(int,char* argv[]) {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    ll x=argv[1][0]-'0';
    while(_--) {
        solve(x);
    }
    return 0;
}