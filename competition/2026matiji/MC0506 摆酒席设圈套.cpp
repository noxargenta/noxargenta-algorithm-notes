#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];

    }
    vector<int> L(n+1,0),R(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j]<a[i]){
                L[i]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]<a[i]){
                R[i]++;
            }
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]==a[j]){
            sum+=(R[j]*L[i]) %10007;   
            }
        }
    }
    cout << sum%10007 << endl;
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