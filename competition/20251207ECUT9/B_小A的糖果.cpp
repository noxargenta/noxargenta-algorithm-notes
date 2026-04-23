#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n ,x;
    cin >> n >> x;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>> a[i];
    }
    int sum=0;
    for(int i=1;i<=n-1;i++){
        if(a[i]+a[i+1]>x){
            int te=a[i+1]+a[i]-x;
            if(te>=a[i+1]){
                a[i+1]=0;
                a[i]-=(te-a[i+1]);
                sum+=te;
                
            }else {
                a[i+1]-=te;
                sum+=te;
            }
        }
    }
    cout << sum << endl;
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