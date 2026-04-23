#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf= 0x7f7f7f7f;
void solve() {
    int n , m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    auto check = [&](int x) -> bool {
        int num = 1;
        int last = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] - last >= x) {
                num++;
                last = a[i];
            }
        }
        return num >= m;
    };
    int lo=0,hi=inf;
    int ans=0;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(check(mid)){
            ans=mid,lo=mid+1;
        }else{
            hi=mid-1;
        }
    }
    cout << ans;
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