#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    int limm=min(n,100LL);
    for(int a=0; a<=limm;a++){
        if((n-a)%12==0){
            string s=to_string(a);
            string r=s;
            reverse(r.begin(),r.end());
            if(r==s){
                cout << a << ' ' << n - a << endl;
                return;
            }
        }
    }
    cout << -1 << endl ;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}