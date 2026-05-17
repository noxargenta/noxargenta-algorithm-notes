#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int ge=0;
vector<int> a(10,0);
int cf(int x){
    while(x!=0){
        ge=x%10;
        x=x%10;
        a[ge]++;
    }
}
void solve() {
    

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