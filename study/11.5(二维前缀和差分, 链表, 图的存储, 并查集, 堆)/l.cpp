#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int n;
    cin >> n;
    priority_queue<int,vector<int>,greater<int>> a;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        a.push(x);
    }
    int sum=0;
    for(int i=0;i<n-1;i++){
        int x=a.top();
        a.pop();
        x+=a.top();
        sum += x;
        a.pop();
        a.push(x);
    }
    cout << sum;
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