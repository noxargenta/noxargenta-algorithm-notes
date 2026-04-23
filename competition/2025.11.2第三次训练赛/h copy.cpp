#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<i64> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<i64> d(n+1,0);
    for(int i=n-1;i>=0;i--){
        i64 v=a[i];
        if((i+1)%2!=0){
            v=-v;
        }
        d[i]=v+d[i+1];
    }
    for(int i=0;i<n;i++){
        int c=s[i]-'a';
        i64 t=d[i];
        int nc=(c+t)%26;
        if(nc<0){
            nc+=26;
        }
        cout << (char)('a'+nc);
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
