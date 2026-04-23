#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,k;
    cin >> n >> k;
    if(k&2==0 && n%2==1){
        cout << "NO\n";
        return;
    }
    vector<int> ans;
    if(k%2==1){
        if(n%2==0){
            
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