#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    string s;
    cin >> s;
    int n=s.length();
    string t1,t2;
    for(int i=0;i<2*n;i++){
        if(i<n){
            t1+='(';
        }else {
            t1+=')';
        }
    }
    for(int i=0;i<n;i++){
        t2+="()";
    }
    if(t1.find(s)==string::npos){
        cout << "YES" << endl;
        cout << t1<< endl;
    }else if(t2.find(s)==string::npos){
        cout << "YES" << endl;
        cout << t2<< endl;
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