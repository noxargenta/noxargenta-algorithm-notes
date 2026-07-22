#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    int a[n];
    int S=0;
    for(int i=0;i<n;i++){
        cin >>  a[i];
        S^=a[i];
    }//ini + 2*(A & B);
    int mask= ~S;
    vector<int> xxj(63,0);
    for(int i=0;i<n;i++){
        int x=a[i]&mask;
        for(int j=30;j>=0;j--){
            if((x>>j)&1){
                if(xxj[j]==0){
                    xxj[j]=x;
                    break;
                }else {
                    x^=xxj[j];
                }
            }
        }
    }
    int sum=0;
    for(int i=30;i>=0;i--){
        sum=max(sum,xxj[i]^sum);
    }
    int ans=S+2LL*sum;
    cout << ans <<endl;
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
//https://ac.nowcoder.com/acm/contest/133877/B