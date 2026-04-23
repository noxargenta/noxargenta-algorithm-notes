#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    long long x;
    cin >> x;
    int num=0;
    while(x>3){
        x=x/4;
        //cout << "xxxxxx"<< x << endl;
        num ++;
    }
    long long t=1;
    for(int i=0;i<num;i++){
        t*=2;
    }
    cout << t << endl;
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