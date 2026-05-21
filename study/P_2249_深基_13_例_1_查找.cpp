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
    while(m--){
        int x;
        cin >> x;
        int l=1,r=n;
        int mid=(l+r)/2;
        while(l<r){
            mid=(l+r)/2;
            if(a[mid]<x){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        if(a[l]==x){
            cout << l << ' ';
        }else {
            cout << -1 << ' ';
        }
        
    }
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