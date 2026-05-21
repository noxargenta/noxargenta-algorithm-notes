#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin  >> n;
    vector<int> a(n+1,0);
    set<int> s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*n;j++){
            if(s.count(j) || (s.count(a[i-1]+j)))continue;
            a[i]=j;
            s.insert(j);
            s.insert(j+a[i-1]);
            break;
        }
    }
    for(int i=1;i<=n;i++){
        cout << a[i] << ' ';
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