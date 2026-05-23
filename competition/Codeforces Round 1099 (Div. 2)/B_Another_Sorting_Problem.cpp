#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    int k=0;
    
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        k=max(k,a[i-1]-a[i]);
    }
    for(int i=2;i<=n;i++){
        if(a[i]<a[i-1]){
            if(a[i]+k<a[i-1]){
                cout << "NO\n";
                return;
            }else {
                a[i]+=k;
            }
        }
    }
    cout << "YES\n";
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