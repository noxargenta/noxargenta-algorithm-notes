#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    map<char,int> a1,b1;
    for(int i=0;i<n;i++){
        a1[a[i]]++;
        b1[b[i]]++;
    }
    for(int i=0;i<n;i++){
        if(a1[a[i]]!=b1[a[i]]){
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