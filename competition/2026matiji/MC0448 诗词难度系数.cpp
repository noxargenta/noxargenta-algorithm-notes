#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
 
struct Query{
    int l,r,x;
};

void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1);
    set<int> s;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        s.insert(i);
    }
    vector<Query> q(m+1);
    for(int i=1;i<=m;i++){
        cin >> q[i].l >> q[i].r >> q[i].x;
    }
    for(int i=m;i>=1;i--){
        int l=q[i].l,r=q[i].r, x=q[i].x;
        auto it=s.lower_bound(l);
        while(it!=s.end() && *it<=r){
            a[*it]=x;
            it=s.erase(it);
        }
    }
    for(int i=1;i<=n;i++){
        cout << a[i] << " " ;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while(_--) {
        solve();
    }
    return 0;
}