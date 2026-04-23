#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n=0;
    cin >>n;
    int count2=0;
    int count3=0;
    int count5=0;
    for (int i=0;i<n;i++){
        int a=0;
        cin >>a;
        while (a>0 && a%2==0){
            count2 ++;
            a/=2;
        }
        while (a>0 && a%3==0){
            count3 ++;
            a/=3;
        }
        while (a>0 && a%5==0){
            count5 ++;
            a/=5;
        }
    }
    cout << min({count2, count3,count5});
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