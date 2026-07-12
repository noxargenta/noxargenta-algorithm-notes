#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> a;
    a.push_back(0);
    a.push_back(2);
    a.push_back(4);
    int sum=2+4;
    if(n<=2){
        for(int i=1;i<=n;i++){
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i=3;i<=n;i++){
        a.push_back(sum);
        sum+=a[i];
    }
    for(int i=1;i<=n;i++){
        cout << a[i] << " ";
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