#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>> a[i];
    }
    cout << (n-1)/2 << endl;
    sort(a.begin(),a.end());
    vector<int> b(n);
    int cur=0;
    for(int i=0;i<n/2;i++){
        b[cur++]=a[n/2+i];
        b[cur++]=a[i];
    }
    if(n%2!=0){
        b[cur++]=a[n-1];
    }
    for(int i=0;i<n;i++){
        cout << b[i] << (i==n-1 ? "" : " ");
    }
    cout << endl;
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
