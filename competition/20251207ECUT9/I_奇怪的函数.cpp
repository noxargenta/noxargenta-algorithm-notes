#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int check(int x){
    int res=1;
    for(int i=0;i<x;i++){
        res*=x;
    }
    return res;
}
void solve() {
    int n;
    cin >> n;
    int res=1;
    for(int i=0;i<n;i++){
        res*=10;
    }
    int xxx=0;
    for(int i=0;;i++){
        if(check(i)>res){
            cout << i-1;
            return;
        }else if(check(i)==res){
            cout << i;
            return;
        }
    }
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