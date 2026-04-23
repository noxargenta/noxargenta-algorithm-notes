#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n+1);
    vector<int> q(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> q[i];
    }
    vector<int> wqhm(n+1);
    for (int i=1;i <=n;i++){
        wqhm[q[i]]=i;
    }
    vector<int> result(n+1);
    for (int i=1;i <=n;i++){
        int person=wqhm[i];
        int person_to=p[person];
        result[i]= q[person_to];
    }
    
    for (int i=1;i <=n;i++){
        cout << result[i] << (i == n ? "" : " ");
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