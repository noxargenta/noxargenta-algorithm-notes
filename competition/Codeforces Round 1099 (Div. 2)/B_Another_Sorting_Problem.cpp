#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin  >> n;
    vector<int> a(n+1,0);
    vector<bool> b(n+1,0);
    int last=a[1];
    for(int i=1;i<=n;i++){
        cin  >> a[i];
        if(i>1){
            if( a[i]<a[i-1]){
                b[i]=1;
                last=a[i-1];
            }
            last=max(last,a[i]);
        }
    }
    for(int i=1;i<=n;i++){
        
    }
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