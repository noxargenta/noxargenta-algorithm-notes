#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n,m;
    cin >> n >> m;
    queue<int> s;
    for(int i=1;i<=n;i++){
        s.push(i);
    }
    while(!s.empty()){
        for(int i=1;i<=m;i++){
            int t=s.front();
            s.pop();
            if(i!=m){
                s.push(t);
            }else {
                cout << t << " ";
            }
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