#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;
    int num=0;
    for (int i=0;i<n;i++){
        string x[n+1];
        cin >> x[i];
        if (x[i]=="and" || x[i]=="not" || x[i]=="that" || x[i]=="the" || x[i]=="you") {
            num++;
        }
    }
    if (num>=1){
        cout << "Yes";
    } else {
        cout << "No";
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