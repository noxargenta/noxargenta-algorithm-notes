#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    vector<string> b(m);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    vector<int> p(m+1);
    for (int i = 0;i<=m; i++) {
        cin >> p[i];
    }
    map<string,int> jiage;
    int defaultp=p[0];
    for (int i = 1;i<=m; i++) {
        jiage[b[i-1]]=p[i];
    }
    i64 sum=0;
    for(string x:a){
        if(jiage.count(x)){
            sum+=jiage[x];
        }else {
            sum+=defaultp;
        }
    }
    cout << sum;
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