#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sum=0;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum+=(a[i]!=i);
    }
    if(n==2 ){
        cout << "Alice\n";
        return;
    }
    if(n==3 && sum==3 && s=="Bob"){
        cout << "Alice\n";
        return;
    }
    cout << "Bob\n";
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