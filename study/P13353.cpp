#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int sum=0;
int xx=0;
int ans=0;
vector<int> G[200005];
void dfs(int t,int fa,int * p){
    xx++;
    for(auto x : G[t]){
        if(x==fa)continue;
        int temp=*(p+x)*xx;
        sum+=temp;
        ans=max(ans,sum);
        dfs(x,t,p);
        xx--;
        sum-=temp;
    }
}
void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n-1;i++){
        int x;
        cin >> x;
        G[x].push_back(i+2);
        G[i+2].push_back(x);
    }
    //sum+=tempa[0];
    dfs(1,0,a);
    
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