#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int n;
    cin >> n;
    vector<array<int,2>> v;
    int ed=n;
    int st=2;
    while ((i64)st*st<n){
        st *= st;
    }
    while(ed>2){
        for(int i=ed-1;i>st;i--){
            v.push_back({i,ed});
        }
        v.push_back({ed,st});
        v.push_back({ed,st});
        ed=st;
        st=sqrt(st);
    }
    cout << v.size() <<endl;
    for(auto [x,y] : v){
        cout << x << ' '<< y << endl;
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