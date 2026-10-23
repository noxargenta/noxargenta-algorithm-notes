#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const ll B=1313137;
const ll MOD=1000000007;

void solve() {
    int n;
    cin >> n;

    string ans,s;
    cin >> ans;

    for(int i=1;i<n;i++){
        cin >> s;

        int m=(int)ans.size();
        int len=min(m,(int)s.size());
        int k=0;
        ll pre=0,suf=0,pw=1;

        for(int j=1;j<=len;j++){
            ll x=(unsigned char)s[j-1]+1;
            ll y=(unsigned char)ans[m-j]+1;

            pre=(pre*B+x)%MOD;    // 前缀右边添加字符
            suf=(y*pw+suf)%MOD;   // 后缀左边添加字符

            if(pre==suf){
                k=j;             // 记录当前匹配的长度
            }

            pw=pw*B%MOD;
        }

        ans+=s.substr(k);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _=1;
    // cin >> _;
    while(_--){
        solve();
    }

    return 0;
}
