#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int dp1[200];
int dp2[200];
void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        dp1[i]=1;
        dp2[i]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j]<a[i]){
                dp1[i]=max(dp1[i],dp1[j]+1);
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(a[j]<a[i]){
                dp2[i]=max(dp2[i],dp2[j]+1);
            }
        }
    }
    int len=0;
    for(int i=0;i<n;i++){
        len=max(len,dp1[i]+dp2[i]-1);
    }
    cout << n - len << endl;
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