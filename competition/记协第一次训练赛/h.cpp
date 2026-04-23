#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >>n;
    int c=0,y=0;
    vector<int> a(n);
    int r=0,l=n-1;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int re;
    int t =0;
    while(r<=l){
        if(a[r]>a[l]){
            re=a[r];
            r++;
        }else{
            re=a[l];
            l--;
        }
        if(t==0){
            c+=re;
        }else {
            y+=re;
        }
        t=1-t;
    }
    cout << c << " "  << y;
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