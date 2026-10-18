#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    ll tmp=n-1;
    vector<ll> f(n+1);
    ll i=1;
    vector<string> a(n + 1);
    vector<vector<ll>> G(n + 1);
    for (ll i = 2; i <= n; i++) {
        ll fu;
        cin >> fu >> a[i];
        G[fu].push_back(i);
    }
    string pat;
    cin >> pat;
    ll m=pat.length();
    vector<ll> nxt(m+1);
    ll j;
    j=nxt[0]=-1;
    i=0;
    while(i<m){
        while(j!=-1 && pat[i]!=pat[j]){
            j=nxt[j];
        }
        nxt[++i]=++j;
    }
    i=0;
    j=0;
    ll ans = 0;

    // 保存：节点编号、到达该节点时的匹配长度
    stack<pair<ll, ll>> st;
    st.push({1, 0});

    while (!st.empty()) {
        auto [u, state] = st.top();
        st.pop();

        for (ll v : G[u]) {
            ll j = state;  // 每个孩子复制父亲的匹配状态

            for (char c : a[v]) {
                // 下面就是你熟悉的普通 KMP
                while (j != -1 && c != pat[j]) {
                    j = nxt[j];
                }
                j++;

                if (j == m) {
                    ans++;
                    j = nxt[j];  // 保留重叠匹配
                }
            }

            st.push({v, j});
        }
    }

    cout << ans << endl;

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