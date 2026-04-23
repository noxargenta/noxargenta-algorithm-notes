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
        a[i]+=a[i-1];
    }
    int sum=0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            bool ok=1;
            int he=a[j]-a[i-1];
            for(int k=i;k<=j;k++){
                if(he%(a[k]-a[k-1])==0){
                    ok=0;
                    break;
                }
            }
            if(ok){
                sum++;
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