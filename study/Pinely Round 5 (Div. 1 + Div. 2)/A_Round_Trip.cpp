#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
const int INF=1e9+9;
void solve() {
    int r0,x0,d,n;
    cin >> r0 >> x0 >> d >> n;
    string s;
    cin >> s;
    vector<int> dp(n+1,INF);
    dp[0]=r0;
    for(auto x : s){
        for(int i=n-1;i>=0;i--){
            if(dp[i]==INF)continue;
            int next=max((int)0,dp[i]-d);
            if(x=='1'){
                dp[i+1]=min(dp[i+1],next);
                dp[i]=INF;
            }else{
                if(dp[i]<x0){
                    dp[i+1]=min(dp[i+1],next);
                    dp[i]=INF;
                }else{
                    continue;
                }
            }
        }
    }
    for(int i=n;i>=0;i--){
        if(dp[i]!=INF){
            cout << i << endl;
            return;
        }
    }
}

signed main() {
    //freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}