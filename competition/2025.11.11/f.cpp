#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int a,b;
    cin >> a >> b;
    if(a%9==0 && b==1){
        cout << "Yes" <<endl;
        return;
    }else if(a+1==b){
        cout << "Yes" << endl;
        return;
    }else {
        int n2=a/9;
        for(int i=1;i<=n2;i++){
            if(a>=(9*i) && a-(9*i)+1==b){
                cout << "Yes\n";
                return;
            }
        }
    }cout << "No\n";
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