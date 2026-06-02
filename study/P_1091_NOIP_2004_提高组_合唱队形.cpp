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
            if(y>=a[i])continue;
            auto it=lower_bound(b1.begin(),b1.end(),y);
            if(it==b1.end()){
                b1.push_back(y);
            }else {
                *it=y;
            }
        }
        for(int j=n-1;j>i;j--){
            int y=a[j];
            if(y>=a[i])continue;
            auto it=lower_bound(b2.begin(),b2.end(),y);
            if(it==b2.end()){
                b2.push_back(y);
            }else {
                *it=y;
            }
        }
        ans=max(ans,(int)(b1.size()+b2.size()+1));
        b1.clear();
        b2.clear();
    }
    cout << n-ans << endl;
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