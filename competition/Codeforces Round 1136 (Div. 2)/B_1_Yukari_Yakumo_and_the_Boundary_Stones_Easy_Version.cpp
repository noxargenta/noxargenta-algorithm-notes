#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll x,y,m;
    cin >> x >> y >> m;
    string s;
    cin >> s;
    ll ans=x+y;

    for(auto xx : s){
        if(xx=='-'){
            if(y>=2){
                y--;
                x++;
            }else if(x>=1){
                x--;
            }else if(y>=1){
                y--;
                x++;
            }
            ans=max(ans,x+y);
        }else{
            if(y>=1){
                y++;
            }else if(x>=1){
                x--;
                y++;
            }
            ans=max(ans,x+y);
        }
    }
    cout << ans << endl;
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