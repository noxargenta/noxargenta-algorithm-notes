#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >> n;
    string s;
    string t;
    cin >> s >> t;
    map<char,int> a;
    map<char,int> a2;
    for(int i=0;i<n;i++){
        a[s[i]]++;
        a2[t[i]]++;
    }
    for(int i=0;i<n;i++){
        if(a[s[i]]!=a2[s[i]]){
            cout << "NO\n";
            return;
        }
    }   
    cout << "YES\n";
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