#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
const int MOD=998244353;
int dp[1 << 22];
int scin[25];
void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i=0;i<n;i++){
        cin >> p[i];
        p[i]--;
    }
    int inv=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[i]>p[j]){
                inv++;
                scin[p[j]] |= (1 << p[i]);
            }
        }
    }
    if(inv==0){
        int ans=1;
        for(int i=1;i<=n;i++){
            ans=i*ans%MOD;
        }
        cout << ans <<endl;
        return;
    }   
    dp[0]=1;
    for(int s=1;s<(1 << n);s++){
        int sum=0;
        for(int u=0;u<n;u++){
            if(s & (1 << u)){
                if((scin[u] & s)==0){
                    sum=(sum+dp[s ^ (1 << u)])%MOD;
                }
            }
        }
        dp[s]=sum;
    }

    cout << 2LL * (dp[(1 << n)-1]) % MOD;
    cout << endl; 
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
//https://ac.nowcoder.com/acm/contest/133877/L