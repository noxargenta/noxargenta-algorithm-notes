#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    string s;
    cin  >> s;
    ll n=s.length();
    for(ll i=0;i<n-1;i++){
        if(s[i]==s[i+1] ){
            cout << n-1 <<endl;
            return;
        }
    }
    cout << n-2 <<endl;
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