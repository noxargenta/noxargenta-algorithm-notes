#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    if(n>21){
        cout << -1 <<endl;
        return;
    }
    int sum=0;
    for(int i=1;i<=7;i++){
        for(int j=1;j<=6;j++){
            if(i%2==1 && sum<n){
                if(j%2==1){
                    cout << 1;
                    sum++;
                }else {
                    cout <<0;
                }
            }else if(i%2!=1 && sum<n){
                if(j%2!=1){
                    cout << 1;
                    sum++;
                }else {
                    cout <<0;
                }
            }else {
                cout << 0;
            }
        }
        cout << endl;
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