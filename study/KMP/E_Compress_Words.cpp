#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
const ull B=131;
const ull MOD1=1000000007;
const ull MOD2=1000000009;

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
        ull pre1=0,suf1=0,pw1=1;
        ull pre2=0,suf2=0,pw2=1;

        for(ll j=1;j<=len;j++){
            ull x=(unsigned char)s[j-1]+1;
            ull y=(unsigned char)ans[m-j]+1;

            pre1=(pre1*B+x)%MOD1;
            suf1=(suf1+y*pw1)%MOD1;

            pre2=(pre2*B+x)%MOD2;
            suf2=(suf2+y*pw2)%MOD2;

            // 两份哈希都相等，才认为匹配
            if(pre1==suf1 && pre2==suf2){
                k=j;
            }

            pw1=pw1*B%MOD1;
            pw2=pw2*B%MOD2;
        }

        ans+=s.substr(k); // 只写一次

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