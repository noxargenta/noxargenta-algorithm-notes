#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >>n;
    map<int,int> a;
    int number=0;
    for(int i=0;i<n;i++){
        cin >> number;
        a[number]++;
    }
    for(auto t:a){
        if(t.second>1){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" <<endl;
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