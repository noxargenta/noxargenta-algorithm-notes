#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int n=0,m=1;
string s1,s2;
void solve() {
    int l,r;
    cin >> l >> r;
    char a;
    for(int i=l;i<=r;i++){
        a=s1[i-1];
        s1[i-1]=s2[i-1];
        s2[i-1]=a;
    }
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    cin >> m;
    cin >> s1 >> s2;
    while(m--) {
        solve();
    }
    cout << s1;
    return 0;
}