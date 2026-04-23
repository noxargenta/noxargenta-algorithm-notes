#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
i64 n,m,k,p,q;
long long check (long long q){
    i64 p=m/q;
    return n*(m-p);
}
void solve() {
    cin >> n >> m >> k;
    i64 l=1,r=1000000001;
    i64 mid=0,ans;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)>=k){
            ans=mid;
            r=mid-1;
        }else {
            l=mid+1;
        }
    }
    cout << ans-1 << endl;
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