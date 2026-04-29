#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int INF=0x3f3f3f3f;
const int INFLL=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n,m;
    cin >> n >> m;
    vector<string> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int ans=0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]==a[j]){
                continue;
            }
            for(int k=0;k<m;k++){
                
                if(a[i][k]!=a[j][k]){
                    ans++;
                }
            }
        }
    }
    cout << ans  << endl;
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