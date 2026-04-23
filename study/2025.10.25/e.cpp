#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n,m;
    cin >> n >>m ;
    string s1,s2;
    cin >> s1 >> s2;
    vector<int> turn(n+2,0);
    for(int i=0;i<m;i++){
        int l,r;
        cin >> l >> r;
        turn[l] ^= 1;
        if(r+1<=n){
            turn[r+1] ^= 1; 
        }
    }
    int on=0;
    for(int i=0;i<n;i++){
        on ^= turn[i+1];
        if(on==1){
            swap(s1[i],s2[i]);
        }
    }
    cout << s1 << "\n";
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