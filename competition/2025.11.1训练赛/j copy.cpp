#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >> n;
    i64 num=0;
    vector<int> a(n);
    if(n%2==0){
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        for(int i=0;i+1<n;i+=2){
            num +=a[i+1]; 
        }
        cout << num << endl;
    }else {
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        for(int i=1;i+1<n;i+=2){
            num +=a[i+1];
        }
        num +=a[0];
        cout << num << endl;
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