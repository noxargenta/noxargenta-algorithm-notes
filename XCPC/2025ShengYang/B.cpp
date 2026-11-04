#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    int n,m;
    ll a,b;
    cin >> n >> m >> a >> b;

    int k=n*m;
    vector<int> cnt(k+1);
    for(int i=0;i<k;i++){
        int x;
        cin >> x;
        cnt[x]++;
    }

    vector<int> f;
    for(int i=1;i<=k;i++){
        if(cnt[i])f.push_back(cnt[i]);
    }
    sort(f.rbegin(),f.rend());

    ll cur=1LL*(k-cnt[0])*a;
    ll ans=cur;
    for(int i=0;i<(int)f.size();i++){
        // 在底部新增纯色图层：透明位置增加擦除代价，同色位置节省绘制代价。
        ll t=max(0LL,a-1LL*i*b);
        cur+=1LL*cnt[0]*b-1LL*f[i]*t;
        ans=min(ans,cur);
    }

    cout << ans << endl;
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