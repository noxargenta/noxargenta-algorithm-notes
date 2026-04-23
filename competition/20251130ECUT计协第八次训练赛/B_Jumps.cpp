#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int x;
    cin >>x;
    int now=0;
    int count=0;
    while(now<x){
        count++;
        now+=count;
    }
    int e=now-x;
    if(e==1){
        cout << count +1<< endl;
    }else {
        cout << count << endl;;
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