#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    vector<int> a;
    int n;
    cin  >> n;
    set<int> s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*n;j++){
            if(s.count(j) || (i>0 && s.count(a[i-1]+j)))continue;
            a.push_back(j);
            s.insert(j);
            s.insert(j+a[i-1]);
        }
    }
    for(auto x : a){
        cout << x  << ' ';
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