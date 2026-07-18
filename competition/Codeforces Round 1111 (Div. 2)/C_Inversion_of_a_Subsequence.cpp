#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    int a[n],b[n];
    string ss1,ss2;
    for(int i=0;i<n;i++){
        cin >> a[i];
        ss1+=a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
        ss2+=b[i];
    }
    if(ss1==ss2){
        cout << 0 << endl;
        return;
    }
    for(int i=0;i<n;i++){
        
    }
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
