#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int n;
    cin >>n;
    vector<int> a(1009,0);
    int maxc=0;
    for(int i=1;i<=n;i++){
        int t1,t2,b;
        cin >> t1 >> t2;
        cin >> b; 
        a[t1]+=b;
        a[t2+1]-=b;
        //maxc=max(c[i],maxc);
    }
    int temp=0;
    for(int i=1;i<=1001;i++){
        temp+=a[i];
        maxc=max(maxc,temp);
    }
    cout << maxc;
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