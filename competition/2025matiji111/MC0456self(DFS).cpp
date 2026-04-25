#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n';
vector<int> G[1000006];
int ans=0;
int n,m;
int dfs(int x,int fa){
    vector<int> son;
    int cur=1;
    for(auto i : G[x]){
        if(i==fa){
            continue;
        }else{
            int sonum=dfs(i,x);  
            son.push_back(sonum);
        }
    }
    
    sort(son.begin(),son.end());
    for(auto y : son){
        if(cur+y<=m){
            cur +=y;
        }else{
            ans++;
        }
    }
    return cur;
}
void solve(){
    cin >> n >> m;
    for(int i=1;i<n;i++){
        int u,v ;
        cin  >> u >> v ;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    dfs(1,0);
    cout << ans+1 << endl;

}   
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _=1;
    //cin >> _;
    while(_--){
        solve();
    }

}