#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int n;
    cin >> n;
    int b;
    priority_queue<int,vector<int>,greater<int>> a;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        switch (x){
        case 1:
            int t;
            cin >> t;
            a.push(t);
            break;
        case 2:
            b=a.top();
            cout << b << endl;
            break;
        case 3:
            a.pop();
            break;
        }
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