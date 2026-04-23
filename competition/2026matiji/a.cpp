#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    int a=0,b=0,c=0,d=0;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        if(x<60){
            a++;
        }else if(x<80){
            b++;
        }else if(x<90){
            c++;
        }else {
            d++;
        }
    }
    cout << a <<' '<<b<<' '<<c<<' '<<d<<endl; 
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