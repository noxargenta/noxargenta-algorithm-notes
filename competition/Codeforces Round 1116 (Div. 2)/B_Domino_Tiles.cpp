#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    bool ok1=0;
    ll pos1=-1,pos2=-1;
    bool ok2=0;
    for(ll i=0;i<n;i++){
        if(i%2==0 && s[i]!='?'&& pos1!=-1){
            ok1=1;
            pos1=i;
        }else if(i%2==1 && s[i]!='?' && pos2!=-1){
            ok2=1;
            pos2=i;
        }
    }
    if(ok1){
        ll l=pos1-2;
        ll r=pos1+2;
        for(;l>=0;l-=2){
            
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