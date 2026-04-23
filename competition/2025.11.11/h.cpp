#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int n;
    cin >> n;
    vector<int> p(4*n+99);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int t=0;
            cin >> t;
            p[i+j]=t;
        }
    }
    set<int> a;
    for(int i=0;i<4*n+99;i++){
        if(p[i]!=0){
            a.insert(p[i]);
        }
    }
    for(int i=1;i<4*n+99;i++){
        if(!a.count(i)){
            p[1]=i;
            break;
        }
    }
    for(int i=0;i<4*n+99;i++){
        if(p[i]!=0){
            cout << p[i] <<" ";
        }
    }cout << endl;
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