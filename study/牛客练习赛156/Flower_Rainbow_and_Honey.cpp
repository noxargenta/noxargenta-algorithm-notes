#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long

string s1,s2;
bool check(ll post){
    string x2;
    ll now=0;
    ll a1=abs(now-post);
    ll a2;
    if(s1[0]=='R'){
        now--;
    }else {
        now++;
    }
    a2=abs(now-post);
    if(a1-a2 < 0){
        x2.push_back('F');
    }else {
        x2.push_back('C');
    }
    a1=a2;
    if(s1[1]=='R'){
        now--;
    }else {
        now++;
    }
    a2=abs(now-post);
    if(a1-a2 < 0){
        x2.push_back('F');
    }else {
        x2.push_back('C');
    }
    if(x2==s2){
        return 1;
    }else {
        return 0;
    }
}
void solve() {
    cin >> s1 >> s2;
    for(ll i=-10;i<=10;i++){
        if(check(i)){
            cout << i << endl;
            return;
        }
    }
    cout << "T_T\n";
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