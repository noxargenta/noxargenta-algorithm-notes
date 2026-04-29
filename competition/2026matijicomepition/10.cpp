#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF=0x3f3f3f3f;
const int INFLL=0x3f3f3f3f3f3f3f3f;
void solve(){
    string s;
    cin >> s;
    int a,b;
    cin >> a >>b;
    cout << s.substr(a,s.length()-a-b) << endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _=1;
    //cin >> _;
    while(_--){
        solve();
    }
}