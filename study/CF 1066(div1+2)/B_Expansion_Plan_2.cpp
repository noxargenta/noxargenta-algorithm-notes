#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,x,y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    int num4=0;
    int num8=0;
    for(int i=0;i< s.length();i++){
        if(s[i]-'0'==4){
            num4++;
        }else {
            num8++;
        }
    }
    x=abs(x);
    y=abs(y);
    if(x<=num8 && y<=num8){
        cout << "YES\n";
    }else if(max((int)0,x-num8)+max((int)0,y-num8)<=num4){
        cout << "YES\n";
    }else {
        cout << "NO\n";
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