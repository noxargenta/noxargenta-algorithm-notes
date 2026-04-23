#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int n;
    i64 l, r;
    cin >> n >> l >> r;
    vector<i64> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int sum=0;
    i64 num=0;
    for(int i=0;i<n;i++){
        num+=a[i];
        if(num>r){
            num=a[i];
        }
        if(num>=l && num<=r){
            sum++;
            num=0;
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