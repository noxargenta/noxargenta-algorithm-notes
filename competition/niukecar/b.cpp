#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,x;
    cin >> n >> x;
    int tsum=0;
    int ssum=0;
    for(int i=n;i>=1;i--){
        tsum+=(i*26);
        ssum+=(i);
        if(tsum>=x){
            break;
        }
        if(n==1 && tsum<x){
            cout << -1 << endl;
        }
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