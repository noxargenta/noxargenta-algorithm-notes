#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const ll B=1313137;
const ll MOD1=1000000007,MOD2=1000000009;

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

        ll pre1=0,suf1=0,pw1=1;
        ll pre2=0,suf2=0,pw2=1;

        for(int j=1;j<=len;j++){
            ll x=(unsigned char)s[j-1]+1;
            ll y=(unsigned char)ans[m-j]+1;

            // 新单词的前缀：右边添加字符
            pre1=(pre1*B+x)%MOD1;
            pre2=(pre2*B+x)%MOD2;

            // 当前答案的后缀：左边添加字符
            suf1=(y*pw1+suf1)%MOD1;
            suf2=(y*pw2+suf2)%MOD2;

            if(pre1==suf1 && pre2==suf2){
                k=j;
            }

            pw1=pw1*B%MOD1;
            pw2=pw2*B%MOD2;
        }

        // 跳过前 k 个重叠字符，追加剩余部分
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
