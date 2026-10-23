#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
const ull B=131;
const ull MOD=1000000007;

void solve() {
    ll n;
    cin >> n;
    string s;
    string ans;
    cin >> ans ;
    
    for(ll i=1;i<n;i++){
        cin >> s;
        ll m=(ll)ans.length();
        ll len=min((ll)ans.length(),(ll)s.length());
        ull pow=1;
        ll k=0;
        ull pre=0,xpre=0;

        for(ll j=1;j<=len;j++){
            ull x=(unsigned char)s[j-1]+10;
            ull y=(unsigned char)ans[m-j]+10;

            pre=(pre*B+x)%MOD;
            xpre=(xpre+y*pow)%MOD;

            if(pre==xpre){
                k=j;
            }

            pow=pow*B%MOD;
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