#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i]%=('z'-'a');
        a[i]=s[i]-a[i];
        if(a[i]<'a'){
            a[i]='a'-a[i];
            cout << char('z'-a[i]);
        }else {
            cout << char(s[i]-a[i]) ;
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