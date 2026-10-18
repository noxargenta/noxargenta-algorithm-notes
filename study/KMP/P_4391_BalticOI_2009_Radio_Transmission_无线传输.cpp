#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long

void solve() {
    ll n;
    cin >>n;
    string s;
    cin >> s;
    vector<ll> next(n+10);
    auto prekmp=[&]()->void{
        ll i,j;
        j=next[0]=-1;
        i=0;
        while(i<n){
            while(j!=-1 && s[i]!=s[j]){
                j=next[j];
            }
            i++;j++;
            next[i]=j;
        }
    };
    prekmp();
    cout << n-next[n] <<endl;
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