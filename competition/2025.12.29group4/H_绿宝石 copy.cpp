#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int a ,b;
    cin >> a  >> b;
    
    if(a<b){
        swap(a,b);
    }
    int cha=a-b;
    int sum=0;
    if(b*2<=a){
        sum+=b;
    }else {
        sum+=cha;
        a-=cha*2;
        b-=cha;
        sum+=((a+b)/3);
    }
    cout << sum << endl;

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