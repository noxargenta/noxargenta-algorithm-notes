#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll a=0,b=0;
    a=count(s.begin(),s.end(),'0');
    b=n-a;
    if(a>b){
        swap(a,b);
    }
    ll cnt = min(a,k);
    a-=cnt;
    b+=cnt;

    cout << 1 +( (a+1) * a /2) + ((b+1) * b/2 ) << endl;
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