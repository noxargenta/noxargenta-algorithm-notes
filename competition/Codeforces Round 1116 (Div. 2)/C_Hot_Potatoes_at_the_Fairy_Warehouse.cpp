#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n,m;
    string s;
    cin >> n >> m;
    cin >> s;
    string s2=s;

    for(ll i=0;i<n-1;i++){
        if(s2[i]=='1' && s2[i+1]=='0'){
            s[i]='0';
            s[i+1]='1';
        }
    }
    if(s2[0]=='0' && s2[n-1]=='1'){
        s[0]='1';
        s[n-1]='0';
    }
    ll a1=0,a2=0;
    for(ll i=0;i<n;i++){
        
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