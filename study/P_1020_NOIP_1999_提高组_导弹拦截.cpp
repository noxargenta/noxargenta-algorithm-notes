#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    vector<int> h;
    int x;
    while(cin  >> x){
        h.push_back(x);
    }
    vector<int> f1;
    for(auto x : h){
        auto it = upper_bound(f1.begin(),f1.end(),x,greater<int>());
        if(it==f1.end()){
            f1.push_back(x);
        }else {
            *it=x;
        }
    }
    cout << f1.size() << endl;
    vector<int> f2;
    for(auto x : h){
        auto it=lower_bound(f2.begin(),f2.end(),x);
        if(it==f2.end()){
            f2.push_back(x);
        }else {
            *it=x;
        }
    }
    cout << f2.size() << "\n";
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