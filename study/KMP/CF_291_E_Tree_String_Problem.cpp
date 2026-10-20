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
    stack<pair<ll,ll>> st;
    //{节点编号，目前长度}
    vector<vector<ll>> go(m+10,vector<ll> (26));
    for(ll i=0;i<m;i++){
        for(ll c=0;c<26;c++){
            char ch=char('a'+c);
            ll k=i;
            while(k!=-1 && ch!=pat[k]){
                k=nxt[k];
            }
            k++;
            go[i][c]=k;
        }
    }
    st.push({1,0});
    while(!st.empty()){
        auto [u,now]=st.top();
        st.pop();
        for(ll v : G[u]){
            ll j=now;
            for(auto c : a[v]){
                j=go[j][c-'a'];

                // while(j!=-1 && c != pat[j]){
                //     j=nxt[j];
                // }
                // j++;
                if(j>=m){
                    ans++;
                    j=nxt[j];
                }
            }
            st.push({v,j});
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