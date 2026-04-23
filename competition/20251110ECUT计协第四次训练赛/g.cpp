#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int k,x;
    cin >> k >> x;
    for(int i=0;i<k;i++){
        int t1,t2;
        t1=(x-1)/3;
        t2=x*2;
        if(t1*3==x-1 && t1%2!=0){
            x=t1;
        }else {
            x=t2;
        }
    }
    cout << x << endl;
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