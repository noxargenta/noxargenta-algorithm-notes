#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int a,b,c,d;
    vector<int> s(4);
    cin >> a ;
    s[0]=a;
    for(int i=1;i<4;i++){
        cin >> s[i];
    }
    sort(s.begin(),s.end());
    for(int i=0;i<4;i++){
        if(s[i]==a){
            cout << 3-i << endl;
            return;
        }
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