#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    i64 d ,k;
    cin >> d >> k;
    i64 x=0;
    for(;x*x*2<=d*d;x+=k);
    x-=k;
    if(x*x+(x+k)*(x+k)<=d*d){
        cout << "Ashish\n";
    }else {
        cout << "Utkarsh\n";
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