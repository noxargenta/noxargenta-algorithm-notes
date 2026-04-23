#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int x;
    cin >> x;
    if(x>45){
        cout << "-1\n";
    }else {
        vector<int> a;
        for(int i=9;i>=1;i--){
            if(x>=i){
                a.push_back(i);
                x-=i;
            }
        }
        sort(a.begin(),a.end());
        for(auto x:a){
            cout << x;
        }
        cout << endl;
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