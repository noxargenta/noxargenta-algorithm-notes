#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,k;
    cin >> n >> k;
    set<int> a;
    map<int,int> m;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        a.insert(x);
        m[x]++;
    }
    if(a.size()<k){
        cout << -1;
    }
    int l=0;
    for(auto x : a){
        l++;
        if(l==k){
            cout << x ;
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