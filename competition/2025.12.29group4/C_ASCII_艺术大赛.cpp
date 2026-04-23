#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    vector<int> a(3);
    for(int i=0;i<3;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    if(a[2]-a[0]>=10){
        cout << "check again";
    }else {
        cout <<"final " <<a[1];
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