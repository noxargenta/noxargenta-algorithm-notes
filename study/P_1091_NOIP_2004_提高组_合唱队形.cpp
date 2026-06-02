#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];

    }
    vector<int> b1;
    vector<int> b2;
    int ans=0;
    for(int i=0;i<n;i++){
        int x=a[i];
        for(int j=0;j<i;j++){
            int y=a[j];
            auto it=lower_bound(b1.begin(),b1.end(),y);
            if(it==b1.end()){
                b1.push_back(y);
            }else {
                *it=y;
            }
        }
        for(int j=i+1;j<n;j++){
            int y=a[j];
            auto it=lower_bound(b1.begin(),b1.end(),y);
            if(it==b1.end()){
                b1.push_back(y);
            }else {
                *it=y;
            }
        }
    }
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