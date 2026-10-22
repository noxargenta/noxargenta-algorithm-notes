#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
unsigned ll val(string s){
    ll va=0;
    for(ll i=0;i<s.length();i++){
        va=va * 131313133 + abs(s[i]-'0');
    }
    return va;
}
void solve() {
    ll n;
    cin >> n;
    vector<unsigned ll> a;
    for(ll i=1;i<=n;i++){
        string s;
        cin >> s;
        a.push_back(val(s));
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    cout << a.size() <<endl;
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