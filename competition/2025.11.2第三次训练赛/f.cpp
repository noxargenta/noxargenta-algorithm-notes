#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int fu=0;
    int lin=0;
    int n;
    cin >>n;
    for(int i=0;i<n;i++){
        int t;
        cin >>   t;
        if(t==0){
            lin++;
        }else if(t < 0){
            fu++;
        }
    }
    int res=0;
    if(fu%2==0){
        res=res;
    }else {
        res+=2;
    }
    res+=lin;
    cout << res << endl;
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