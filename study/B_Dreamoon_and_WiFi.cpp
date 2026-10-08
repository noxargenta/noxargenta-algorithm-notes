#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
string s1,s2;
ll cnt=0;
ll need=0;
void dfs(ll i,ll now){
    if(i==s1.length()){
        if(now==need){
            cnt++;
        }
        return;
    }
    if(s2[i]=='+'){
        now++;
        dfs(i+1,now);
    }else if(s2[i]=='-'){
        now--;
        dfs(i+1,now);
    }else {
        dfs(i+1,now-1);
        dfs(i+1,now+1);
    }
}
void solve() {
    cin >> s1 >> s2;
    for(auto x : s1){
        if(x=='+'){
            need++;
        }else {
            need--;
        }
    }
    ll xx=0;
    for(auto x : s2){
        if(x=='?'){
            xx++;
        }
    }
    dfs(0,0);
    cout << fixed << setprecision(12) ;
    cout << (double)cnt*1.0/(1LL << xx) <<endl;

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