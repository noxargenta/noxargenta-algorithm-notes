#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
ll B=131313137;
void solve() {
    ll n;
    cin >> n;
    string s;
    string ans;
    cin >> ans ;
    ull pre=0;
    ull xpre=0;
    for(ll i=1;i<n;i++){
        cin >> s;
        ll m=(ll)ans.length();
        ll len=min((ll)ans.length(),(ll)s.length());
        ll pow=1;
        ll k=0;
        for(ll j=1;j<len;j++){
            ull x=s[j-1]-'a'+1;
            ull y=ans[m-j]-'a'+1;
            pre=(pre*B + x );
            xpre=(xpre + y * pow);
            pow*=B;
            if(pre== xpre){
                k=j;
            }
        }
        ans+=s.substr(k);
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