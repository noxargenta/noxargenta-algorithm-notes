#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF=0x3f3f3f3f;
const int INFLL=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n,m;
    cin >> n >> m;
    int a[n+1];
    vector<bool> vis(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    a[0]=0;
    int ans=0;
    for(int i=1;i<=m;i++){
        int t,z;
        cin >> t >> z;
        //cout << "t:" << t <<"----"<< endl;
        int last=0;
        for(int j=t;j<=n;j++){
            //cout << "j=" << j << endl;
            
            if(last==0 && a[j]<=z && vis[j]==0){
                last=j;
            }
            
            if(vis[j]==1){
                continue;
            }
            if(vis[last]==1 && a[j] <z){
                last=j;
            }
            if(a[j]>a[last] && a[j]<=z ){
                last=j;
            }
            //cout << " last:" << last << endl;
            if(a[last]==z){
                vis[last]=1;
                ans+=a[last];
                break;
            }
            
            
        }
        if(vis[last]==0){
            ans+=a[last];
            vis[last]=1;
            //cout << last<< endl;
        }
        // cout << a[last] << endl;
        //cout << i << "ans:" << ans<< endl;
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _=1;
    cin >> _;
    while(_--){
        solve();
    }
}