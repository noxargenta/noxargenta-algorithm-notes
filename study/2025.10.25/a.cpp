#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> s(n);
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    for(int i=0;i<m;i++){
        int q;
        cin >> q;
        auto it=lower_bound(s.begin(),s.end(),q);
        int index=distance(s.begin(),it);
        if(index<n && s[index]==q){
            cout << index +1 << " ";
        }else {
            cout << "-1" << " " ;
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