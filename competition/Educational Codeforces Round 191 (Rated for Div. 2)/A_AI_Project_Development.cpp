#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,x,y,z;
    cin >> n >> x >> y >> z;
//     //四个整数 n
//  、 x
//  、 y
//  和 z
//  ( 1≤n,x,y,z≤10000
//  )，分别是项目中的行数、Maxim 的速度、Nikita 在没有 AI 的情况下的速度以及 AI 设置时间。
    if(n<=z*x){
        cout << (n+1)/(x+y) << endl;
    }else {
        cout << z + (n-z*x+1)/()
    }
    cout << min((n+1)/(x+y),min())


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