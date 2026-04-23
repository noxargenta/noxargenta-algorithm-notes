#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf=0x3f3f3f3f;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum=0;
    int mn=inf;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
        mn =min(mn,a[i]);
    }
    auto check = [&](int x) -> bool{
        vector<int> add(n);
        bool ok=true;
        for(int i=n-1;i>1;i--){
            ok &= (a[i] + );
        }   
    };
    
    int l=mn,r=inf,ans=mn;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid,l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout << ans;
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