#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n,k;
    cin >> n >> k;
    set<int> a;
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        a.insert(t);
    }
    int i=0;
    if(a.size()<k){
    cout << "NO RESULT";        
    }
    for(auto &t : a){
        i++;
        if(i==k){
            cout << t;
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