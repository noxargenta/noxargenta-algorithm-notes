#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'

void solve() {
    int n,m;
    cin >> n >> m;

    string s;
    cin >> s;
    s=" "+s;

    const ll B=131;
    const ll MOD1=1000000007;
    const ll MOD2=1000000009;

    vector<ll> p1(n+1,1),p2(n+1,1);
    vector<ll> h1(n+1),h2(n+1);
    vector<ll> one1(n+1),one2(n+1);
    vector<int> cnt(n+1);

    for(int i=1;i<=n;i++){
        int x=s[i]-'0';

        // B 的幂
        p1[i]=p1[i-1]*B%MOD1;
        p2[i]=p2[i-1]*B%MOD2;

        // 原串的前缀哈希
        h1[i]=(h1[i-1]*B+x)%MOD1;
        h2[i]=(h2[i-1]*B+x)%MOD2;

        // 长度为 i 的全 1 字符串的哈希
        one1[i]=(one1[i-1]*B+1)%MOD1;
        one2[i]=(one2[i-1]*B+1)%MOD2;

        // 前 i 个字符中 1 的数量
        cnt[i]=cnt[i-1]+x;
    }

    // 计算排序 [l,r] 后的完整字符串哈希
    auto calc = [&](int l,int r,
        vector<ll>& h,
        vector<ll>& p,
        vector<ll>& one,ll mod)->ll{
        int len=r-l+1;
        int k=cnt[r]-cnt[l-1];

        ll left=h[l-1];

        // 中间排序后为若干个 0 + k 个 1
        ll mid=one[k];

        ll right=(h[n]-h[r]*p[n-r]%mod+mod)%mod;

        // 拼接左边和中间
        ll res=(left*p[len]+mid)%mod;

        // 再拼接右边
        res=(res*p[n-r]+right)%mod;

        return res;
    };
    //////////////
    set<pair<ll,ll>> st;

    while(m--){
        int l,r;
        cin >> l >> r;

        ll x=calc(l,r,h1,p1,one1,MOD1);
        ll y=calc(l,r,h2,p2,one2,MOD2);

        st.insert({x,y});
    }

    cout << st.size() << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _=1;
    cin >> _;
    while(_--){
        solve();
    }
    return 0;
}
