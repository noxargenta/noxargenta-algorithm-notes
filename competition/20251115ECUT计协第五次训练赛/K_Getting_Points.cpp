#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
bool check(i64 mid,i64 n,i64 c,i64 f, i64 p){
    i64 s=(n-1)/7+1;
    return c*min(mid*2,s) + f*mid >=p;
};
void solve() {
    i64 n,p,f,c;
    cin >> n >> p >> f >> c;
    
    i64 l=0,r=n+99;
    i64 ans=0;
    while(l<=r){
        i64 mid =(r+l)/2;
        if(check(mid,n,c,f,p)){
            ans=mid;
            r=mid-1;
        }else {
            l=mid+1;
        }
    }
    cout << n-ans << endl;
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