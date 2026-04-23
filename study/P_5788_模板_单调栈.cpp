#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<int> ans(n+1);
    stack<int> s;
    for(int i=n;i>=1;i--){
        while(!s.empty() && a[i]>=a[s.top()]){
            s.pop();
        }
        if(s.empty()){
            ans[i]=0;
        }else {
            ans[i]=s.top();
        }
        s.push(i);
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
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