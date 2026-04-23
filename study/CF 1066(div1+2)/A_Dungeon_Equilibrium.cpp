#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
const int INF=0x7f7f7f7f;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1),b(n+1);
    int sum=0;
    for(int i=1;i<=n;i++){
        int t;
        cin >> t;
        b[i]=t;
        a[t]++;
        if(a[t]>t){
            sum ++;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[b[i]]<b[i]){
            sum+=a[b[i]];
            a[b[i]]+=b[i];
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