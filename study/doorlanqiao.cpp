#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int a2(int x){
    int ans=0;
    while(x!=0){
        int y=x%10;
        x/=10;
        if(y==2){
            ans++;
        }
    }
    return ans;
}
void solve() {
    int ans=0;
    for(int i=1;i<=2020;i++){
        ans+=a2(i);
    }
    cout  << ans <<endl;
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