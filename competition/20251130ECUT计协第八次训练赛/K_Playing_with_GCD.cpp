#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<int> b(n+2);
    b[1]=a[1],b[n+1]=a[n];
    for(int i=2;i<=n;i++){
        b[i]=a[i-1]*a[i]/gcd(a[i],a[i-1]);
    }
    int ok=1;
    for(int i=1;i<=n;i++){
        if(a[i]!=gcd(b[i],b[i+1])){
            ok++;
            break;
        }
    }
    if(ok==1){
        cout << "yes\n";
    }else {
        cout << "no\n";
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