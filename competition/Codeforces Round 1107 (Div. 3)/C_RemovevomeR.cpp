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
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            sum++;
        }
    }
    if(sum==1){
        cout << 2 << endl;
    }else {
        cout << 1 << endl;
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