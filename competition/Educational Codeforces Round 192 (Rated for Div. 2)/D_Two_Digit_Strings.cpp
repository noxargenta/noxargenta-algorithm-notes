#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
string sa;
string sb;
int dp[(int)(5*1e3+1)][(int)(5*1e3+1)];
vector<int> a(5*1e3+1,0),b(5*1e3+1,0);
void solve() {
    cin >> sa >> sb;
    int ca=sa.length();
    int cb=sb.length();
    sa='0'+sa;
    sb='0'+sb;
    for(int i=1;i<=ca;i++){
        a[i]=(a[i-1]+(sa[i]-'0'))%10;
    }
    for(int i=1;i<=cb;i++){
        b[i]=(b[i-1]+(sb[i]-'0'))%10;
    }
    if(a[ca]!=b[cb]){
        cout << -1 << endl;
        return;
    }
    for(int i=1;i<=ca;i++){
        for(int j=1;j<=cb;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(a[i]==b[j]){
                dp[i][j]=max(dp[i-1][j-1]+1,dp[i][j]);
            }
        }
    }
    int ans=dp[ca][cb];
    if(ans==0){
        cout << -1 << endl;
    }else {
        cout << ans << endl;
    }
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}