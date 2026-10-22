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
        while(j!=-1 && s[i]!=s[j]){
            j=nxt[j];
        }
        if(s[++i]==s[++j]){
            nxt[i]=nxt[j];
        }else {
            nxt[i]=j;
        }
    }
    ll ans=0;
    for(ll i=2;i<m;i++){
        ll j=i;
        ll low=(i+1)/2;
        ll maxx=0;
        while(j>=low){
            
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