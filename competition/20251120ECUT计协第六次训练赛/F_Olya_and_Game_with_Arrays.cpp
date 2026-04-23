#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int a[50005];
void solve() {
    
    int n,m;
    cin >> n;
    int min1=2e9,min2=2e9,sum=0;
    for(int i=1;i<=n;i++){
        cin >> m;
        for(int j=1;j<=m;j++){
            cin >> a[j];
        }
        sort(a+1,a+1+m);
        min1=min(min1,a[1]);
        min2=min(min2,a[2]);
        sum+=a[2];
    }
    cout << sum - min2+min1 << endl;
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