#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    priority_queue<int> max_;
    priority_queue<int ,vector<int>,greater<int>> min_;
    int x;
    for(int i=1;i<=n;i++){
        cin >> x;
        max_.push(x);
        min_.push(max_.top());
        max_.pop();
        if(min_.size()>max_.size()){
            max_.push(min_.top());
            min_.pop();
        }
        
    cout << max_.top() << " ";
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