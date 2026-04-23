#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(n%2==0){
        cout << "2\n1 "<< n <<endl << "1 "<< n << endl;
    }else {
        cout << "4\n";
        cout << "1 "<< n-1 << endl;
        cout << "1 "<< n-1 << endl;
        cout << n-1<<" "<< n << endl;
        cout << n-1<<" "<< n << endl;
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