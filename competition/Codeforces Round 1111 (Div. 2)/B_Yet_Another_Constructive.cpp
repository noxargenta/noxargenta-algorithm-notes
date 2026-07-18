#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,k,m;
    cin >> n >> k >> m;
    if(k>m){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i=1;i<=n;i++){
        if(i%k!=0){
            cout << "1" << " ";
        }else {
            cout << m-k+1 << " ";
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