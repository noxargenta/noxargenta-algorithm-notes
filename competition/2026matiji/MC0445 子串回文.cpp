#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    string s;
    cin >> s;
    int ans=0;
    int n=s.length();
    for(int i=0;i<n;i++){
        for(auto k : {0,1}){
            int l=i,r=i+k;
            while(l>=0 && r<n && s[l]==s[r]){
                ans++;
                l--;
                r++;
            }
        }
    }
    cout << ans << endl;
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