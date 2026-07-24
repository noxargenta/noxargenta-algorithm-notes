#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int dp[30][4];
int cnt[30][4];
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<30;j++){
            int x1=(a[i] >> j)&1;
            int x2;
            if(j==0){
                x2=0;
            }else {
                x2=(a[i] >> (j-1)) & 1;
            }
            int y=(x1 << 1) | (x2 << 0);
            cnt[j][y]++;
        }
    }
    for(int i=0;i<30;i++){
        for(int j=0;j<4;j++){
            dp[i][j]=j;
        }
    }

    int m;
    cin >> m;
    while(m--){
        int op,x;
        cin >> op >> x;
        int sum=0;
        for(int i=0;i<30;i++){
            int x1=(x >> i)&1;
            int x2;
            if(i==0){
                x2=0;
            }else {
                x2=(x >> (i-1)) & 1;
            }
            int y=(x1 << 1) | (x2);
            for(int j=0;j<4;j++){
                if(op==1){
                    dp[i][j]&=y;
                }else if(op==2){
                    dp[i][j]|=y;
                }else if(op==3){
                    dp[i][j]^=y;
                }
            }
        }
        for(int i=0;i<30;i++){
            for(int j=0;j<4;j++){
                if(dp[i][j]==2){
                    sum+=cnt[i][j];
                }
            }
        }
        cout << sum << endl;
    }
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