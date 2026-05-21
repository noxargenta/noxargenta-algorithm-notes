#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    int l=1,r=4*1e5;
    auto ok = [&](int x){
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=max(a[i]-x,(int)0);
        }
        if(sum>=m){
            return 1;
        }else {
            return 0;
        }
    };
    while(l<r){
        int sum=0;
        int mid=(l+r)/2;
        if(ok(mid)){
            l=mid+1;
        }else {
            r=mid;
        }
    }
    cout << l-1 << endl;
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