#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

i64 jiecheng(int x){
    i64 res=1;
    for (int i=0;i<x;i++){
        res*=i;
    }
    return res;
}

i64 zhuchiren(int n,int k){
    i64 res2;
    res2=jiecheng(n)/(jiecheng(n)*jiecheng(n-k));
    return res2;
}
void solve() {
    i64 t;
    cin >> t;
    for (int i=0;i<t; i++){
        i64 n,k,r;
        cin >> n >> k >> r ;
        i64 b=n-k;
        i64 result=0;
        result=zhuchiren(n,k)*(jiecheng(n-k)/jiecheng(n-k-r));
        cout << result <<endl;
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