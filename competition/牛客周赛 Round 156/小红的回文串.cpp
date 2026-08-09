#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
bool check(string s ){
    string s2=s;
    reverse(s.begin(),s.end());
    if(s2==s){
        return 1;
    }
    return 0;
}
void solve() {
    ll n;
    cin >> n;
    string s;
    ll ans=0;
    cin >> s;
    for(char c='a' ;c-'a'<=26;c++){
        string s2;
        for(ll i=0;i<n;i++){
            if(s[i]==c)continue;
            s2+=s[i];
        }
        if(check(s2)){
            ans++;
        }
    }
    cout << ans <<endl;
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