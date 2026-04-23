#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int t;
    cin >> t;
    i64 suma=0;
    vector<i64> a(t+1);
    for(int i=1;i<=t;i++){
        cin >> a[i];
        suma+=a[i];
    }
    if(t<=2){
        cout << "-1\n";
        return;
    }
    sort(a.begin()+1,a.end());
    i64 sum=a[t/2+1]*2*t+1;
    sum-=suma;
    if(sum<0){
        sum=0;
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