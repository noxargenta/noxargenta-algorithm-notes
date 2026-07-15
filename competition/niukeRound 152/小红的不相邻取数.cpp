    #include <bits/stdc++.h>
    using namespace std;
    using i64 = long long;
    #define endl '\n'
    #define int long long
    const int INF=2e18+9; 
    void solve() {
        int n;
        cin >> n;
        vector<int> a(n+1),b(n+1);
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        for(int i=1;i<=n;i++){
            cin >> b[i];
        }
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        dp[0][0]=0;
        dp[0][1]=-INF;
        for(int i=1;i<=n;i++){
            int x=a[i];
            int k=b[i];
            if(x<=0){
                dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
                dp[i][1]=-INF;
            }else {
                int f0=dp[i-1][0] + (k/2)*x;
                int f1=dp[i-1][1] + ((k-1)/2)*x;
                dp[i][0]=max(f1,f0);

                f0=dp[i-1][0] + ((k+1)/2)*x;
                f1=dp[i-1][1] + (k/2)*x;
                dp[i][1]=max(f0,f1);
            }
        }
        cout << max(dp[n][0],dp[n][1]);
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