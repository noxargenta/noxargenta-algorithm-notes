#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int most(int x){
    int pos=0;
    while(x>0){
        x/=2;
        pos++;
    }
    return pos;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<int> cnt(99,0);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        cnt[most(a[i])]++;
    }
    int ans=0;
    for(auto x : cnt){
        ans+=x*(x-1)/2;
    }
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