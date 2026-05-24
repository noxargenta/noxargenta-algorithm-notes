#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve(){
    string s;
    cin >> s;
    for(int i=s.length()-1;i>=0;i--){
        cout << s[i];
    }
}
signed main(){
    int _=1;
    //cin >>_;
    while(_--){
        solve();
    }
}
