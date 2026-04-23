#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
vector<int> G[200005];
int a[200005],b[200005];
void solve() {
    int n;
    cin >> n;
    for(int i=1;i<n;i++){/////
        int v,u;
        cin >> v >> u;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++){////
        cin >> a[i];
        b[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        sort(G[i].begin(),G[i].end(),[&](int x,int y){
            return b[x]<b[y]; 
        });
    }
    vector<int> runans;
    runans.push_back(-999);
    queue<int> q;
    q.push(1);
    vector<bool> visit(200005,0);
    while(!q.empty()){
        int u=q.front();
        visit[u]=1;
        q.pop();
        runans.push_back(u);
        for(auto x : G[u]){
            if(visit[x]==1){
                continue;
            }else{
                q.push(x);
                visit[x]=1;
            }
        }   
    }
    for(int i=1;i<=n;i++){
        if(runans[i]!=a[i]){/////////////
            cout << "No\n" << endl;
            return;
        }
    }
    cout << "Yes\n" << endl;
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