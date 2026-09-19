#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
char y[]={'A', 'O', 'Y', 'E', 'U', 'I','a', 'o', 'y', 'e', 'u', 'i'};
bool check(char x){
    for(auto a : y){
        if(x==a){
            return 1;
        }
    }
    return 0;
}
void solve() {
    string s;
    cin >> s;
    for(auto x : s){
        if(!check(x)){
            cout << '.';
            if(x>='A' && x <='Z'){
                cout << char(x-('A'-'a'));
            }else {
                cout << x;
            }
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