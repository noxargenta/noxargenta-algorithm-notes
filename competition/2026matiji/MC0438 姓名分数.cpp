#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m;
    cin >> n ;
    set<string> s;
    for(int i=1;i<=n;i++){
        string x;
        cin   >> x;
        s.insert(x);
    }
    cin >> m;
    map<string,int> m;
    for(int i=1;i<=m;i++){
        int opt;
        cin >> opt;
        if(opt==1){
            string x;
            cin >> x;
            int x2;
            cin >> x2;
            
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