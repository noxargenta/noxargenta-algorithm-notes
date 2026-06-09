#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    double n;
    int x,y,z;
    cin >> n >> x >> y >> z;
//     //四个整数 n
//  、 x
//  、 y
//  和 z
//  ( 1≤n,x,y,z≤10000
//  )，分别是项目中的行数、Maxim 的速度、Nikita 在没有 AI 的情况下的速度以及 AI 设置时间。
    double ans;
    if(z + (n-z*x)/(10*y + x)>0){
        ans=min((n)/(x+y),z + (n-z*x)/(10*y + x));
    }else {
        ans=ceil((n*1.0)/(x+y));
    }
    if((ans-(int)ans<1e-9)){
        cout << ans << endl;
    }else {
        cout << (int)ans+1 << endl;
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