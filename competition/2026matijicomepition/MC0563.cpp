#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m;
    cin >> n  >> m;
    vector<set<char>> se(m);
    vector<string> s(n);
    vector<map<char,int>> ma(m);
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            se[j].insert(s[i][j]);      
            ma[j][s[i][j]]++;
        }
    }
    int ans=0;
    for(int i=0;i<m;i++){
        for(auto x : se[i]){
            ans+=(ma[i][x]*(n-ma[i][x]));
        }
    }
    cout << ans/2 << endl;

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