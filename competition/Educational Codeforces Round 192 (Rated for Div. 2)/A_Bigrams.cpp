#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    int a2=0;
    int a3=0;
    while(n--){
        int x;
        cin >> x;
        if(x>=3){
            a3++;
        }else if(x>=2){
            a2++;
        }
    }if(a2>=2 || a3>0){
        cout << "YES\n";
    }else  {
        cout << "NO\n";
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