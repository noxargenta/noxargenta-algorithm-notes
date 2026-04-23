#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> num(n);
    for (int i=0;i<n;i++){
        num[i]=i+1;
    }
    int now=0;
    for (int i=0; i<n; i++){
        now=(now-1+m)%num.size();
        cout << num[now];
        if (i<n){
            cout << " ";
        }
        num.erase(num.begin()+now);
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