#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m;
    int a[n+1];
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    while(m--){
        int x;
        cin >> x;
        int sum=0;
        for(int i=1;n-i+1>=x;i++){
            set<int> st;
            for(int j=i;j<i+x;j++){
                st.insert(a[i]);
            }
            sum+=st.size();
        }
        cout << sum <<endl;
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