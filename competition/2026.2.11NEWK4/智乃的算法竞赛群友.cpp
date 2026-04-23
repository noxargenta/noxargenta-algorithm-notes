#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,a,b;
    cin >> n >> a >> b;
    vector<array<int,3>> v(3);
    v[0] = {16 * a, 7, a};
    v[1] = {56 * b, 2, b};
    v[2] = {14 * (a + b), 8, a + b};
    sort(v.begin(), v.end(), greater());
    int ans=0;
    if(n>200){
        int k=(n-200)/v[0][1];
        ans+=k*v[0][2];
        n-=k*v[0][1];
    }
    int ans2=0;
    for(int i=0;i*7<=n;i++){
        for(int j=0;i*7 + j*8 <=n;j++){
            int c=n-(i*7 + j*8);
            int k=c/2;
            ans2=max(ans2,i*a+j*(a+b)+k*b);
        }
    }
    cout << ans + ans2<< endl;

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