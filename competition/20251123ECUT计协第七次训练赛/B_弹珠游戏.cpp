#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    int ans=0,sum=0;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        a[x]++;
    }   
    for(int i=0;i<=n;i++){
        if(a[i]==1){
            sum ++;
        }else if(a[i]>1){
            ans++;
        }
    }
    ans+=(sum+1)/2*2;
    cout << ans << endl;
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