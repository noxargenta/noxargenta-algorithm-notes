#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1e18;
// struct Node{
//     ll val;
//     ll y,x;
// };
// ll dx[2]={1,0};
// ll dy[2]={0,1};
void solve(){
    ll n;
    cin >> n;
    ll a[n];
    ll g[n][n];
    for(ll i=0;i<n;i++){
        cin >> a[i];
        g[i][0]=a[i];
    }
    for(ll j=1;j<n;j++){
        for(ll i=0;i<n;i++){
            if(i==0){
                g[i][j]=g[n-1][j-1];
            }else {
                g[i][j]=g[i-1][j-1];
            }
        }
    }
    // for(ll j=0;j<n;j++){
    //     for(ll i=0;i<n;i++){
    //         cout << g[j][i] << " ";
    //     }
    //     cout << endl;
    // }
    ll dp[n+1][n+1];
    for(ll i=0;i<n;i++){
        for( ll j =0;j<n;j++){
            dp[i][j]=0;
        }
    }
    for(ll i=0;i<n;i++){
        if(i>0){
            dp[0][i]=g[0][i]+dp[0][i-1];
        }else {
            dp[0][i]=g[0][i];
        }
        
    }

    for(ll i=1;i<n;i++){
        for(ll j=0;j<n;j++){
            if(j==0){
                dp[i][j]=g[i][j]+dp[i-1][j];
            }else {
                dp[i][j]=min(dp[i-1][j],dp[i][j-1]) + g[i][j];
            }
        }
    }
    cout << dp[n-1][n-1] << endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll _=1;
    cin >> _;
    while(_--){
        solve();
    }
}