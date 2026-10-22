#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll m=s.length();
    vector<ll> nxt(n+1);
    ll i,j;
    j=nxt[0]=-1;
    i=0;
    while(i<m){
        while(j!=-1 && s[i]!=s[j])[
            j=nxt[j];
        }
        
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