#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
ll dx[]={1,0,-1,0};
ll dy[]={0,-1,0,1};
char dd[]={'D', 'L', 'U', 'R'};
void solve() {
    ll n,m;
    cin >> n >> m;
    vector<vector<bool>> vis(n,vector<bool>(m,0));
    vector<string> a(n);

    ll xxx=-1,yyy=-1;
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(a[i][j]=='S'){
                xxx=i;
                yyy=j;
                break;
            }
        }
        if(xxx!=-1){
            break;
        }
    }

    string ans;
    function<void(ll,ll)> dfs=[&](ll x,ll y){
        for(ll i=0;i<4;i++){
            ll x2=x+dx[i];
            ll y2=y+dy[i];
            if(x2>=0 && x2 <n && y2>=0 && y2 <m){

                if(!vis[x2][y2] && a[x2][y2]=='*'){
                    cout << dd[i];
                    vis[x2][y2]=1;
                    dfs(x2,y2);
                }
            }
        }
    };
    dfs(xxx,yyy);
    
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