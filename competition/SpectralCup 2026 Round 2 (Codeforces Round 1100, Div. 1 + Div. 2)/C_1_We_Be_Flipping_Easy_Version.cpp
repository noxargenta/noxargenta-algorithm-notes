#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int sum=0;
    bool fil=1;
    vector<int> b;
    for(int i=n;i>=1;i--){
        if(a[i] * fil>0){
            sum++;
            b.push_back(i);
            fil*=-1;
        }
    }
    cout << sum<< endl;
    for(auto x : b){
        cout << x << ' ';
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