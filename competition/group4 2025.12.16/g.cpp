#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    string s;
    cin >> s;
    int n=s.size();
    string s1[n];
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]!='0'){
            ans++;
            s1[i]=s[i];
            s1[i]+=string(n-1-i,'0');
        }
    }
    cout << ans << endl;
    for(int i=0;i<n;i++){
        if(s[i]!='0'){
            cout << s1[i] << " " ;
        }
    }
    cout << endl;
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