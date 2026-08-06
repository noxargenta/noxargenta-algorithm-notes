#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
ll n;string s;ll n0=0;
    ll n1=0;string ss;
ll get_len(char x,char y){
    int ans=ss.length();
    if(x!=ss.front()){
        ans--;
    }
    if(y!=ss.back()){
        ans--;
    }
}
void solve() {
    
    cin >> n;
    
    cin >> s;
    
    
    for(auto x : s){
        if(x=='0'){
            n0++;
        }else n1++;
        if(ss.empty() || ss.back()!=x){
            ss.push_back(x);
        }
    }
    if(abs(n1-n0)>=3){
        cout << -1<<endl;
        return;
    }
    ll anss=-1;
    for(ll d=-1;d<2;d++){
        
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