#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
vector<int> G[200005];
int w[200005];
int size_w[200005];
int sum_w[200005];
int sum=0;
int sutime=0;
void dfsp(int u,int fa){
    size_w[u]=1;
    sum_w[u]=w[u];
    for(auto v : G[u]){
        if(v==fa)continue;
        dfsp(v,u);
        size_w[u]+=size_w[v];
        sum_w[u]+=sum_w[v];
    }
}
void dfs(int u,int fa){
    sutime++;
    sum+=w[u]*sutime;
    vector<int> chil;
    for(auto v : G[u]){
        if(v!=fa){
            chil.push_back(v);
        }
    }
    sort(chil.begin(),chil.end(),[&](int ch1,int ch2){
        return sum_w[ch1]*size_w[ch2]<sum_w[ch2]*size_w[ch1];
    });
    for(auto vv:chil){
        dfs(vv,u);
    }
}
void solve() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> w[i];
    }
    for(int i=2;i<=n;i++){
        int x;
        cin >> x;
        G[x].push_back(i);
        G[i].push_back(x);
    }
    dfsp(1,0);
    dfs(1,0);
    cout << sum << endl;
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