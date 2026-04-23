#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >> n;
    priority_queue<int,vector<int>,greater<int>> a;
    for(int i=0;i<n;i++){
        int t=0;
        cin >> t;
        a.push(t);
    }
    int num=0;
    for(int i=0;i<n-1;i++){
        int t=a.top();
        a.pop();
        int t2=a.top();
        a.pop();
        t=t+t2;
        num+=t;
        a.push(t);
    }
    cout << num;
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