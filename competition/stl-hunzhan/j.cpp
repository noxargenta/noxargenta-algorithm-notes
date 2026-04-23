#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    i64 m;
    cin >> n >> m;
    vector<int> s(n);
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    if (n <= 1) {
        cout << 0 << endl;
        return;
    }
    sort(s.begin(),s.end());
    int zi=1;
    int maxl=1;
    for(int i=1;i<n;i++){
        if(s[i]-s[i-1]<=m){
            zi++;
        }else {
            maxl=max(zi,maxl);
            zi=1;
        }
    }
    maxl=max(zi,maxl);
    cout << n - maxl<< endl;
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}