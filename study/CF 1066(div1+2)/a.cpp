#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
const int INF=0x7f7f7f7f;
void solve() {
    vector<int> a(INF);
    int n;
    cin >> n;
    int sum=0;
    for(int i=1;i<=n;i++){
        int t;
        cin >> t;
        a[t]++;
        if(a[t]>t){
            sum ++;
        }   
    }
    cout << sum << endl;

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