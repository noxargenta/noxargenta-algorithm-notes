#include <bits/stdc++.h>
using namespace std;
using i64 = unsigned long long;
void solve() {
    int n,k;
    cin >> n >> k;
    vector<vector<int>> a(n,vector<int>());
    for(int i=0;i<n;i++){
        int day=0,num=0;
        cin >> day >> num;
        for (int j=0;j<day;j++){
            a[j]+=num;
        }
        if(a[i]<=k){
            cout << i+1;
            return;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]<=k){
            cout << i+1;
            return;
        }
    }
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 _ = 1;
    // cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}