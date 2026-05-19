#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> a(3*n+1);
    for(int i=1,j=1;i<=n;i++,j+=3){
        a[j]=i;
    }
    for(int i=n+1,j=2;i<=3*n;i+=2,j+=3){
        a[j]=i;
        a[j+1]=i+1;
    }
    for(auto x : a ){
        if(x==0){
            continue;
        }
        cout <<  x << ' ' ;
    }
    cout << endl ;
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