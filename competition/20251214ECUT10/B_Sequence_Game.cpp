#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    int minxx=0x7f7f7f7f;
    int maxx=-0x7f7f7f7f;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        minxx=min(minxx,a[i]);
        maxx=max(maxx,a[i]);
    }
    int x;
    cin >> x;

    if(x>=minxx&&x<=maxx){
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