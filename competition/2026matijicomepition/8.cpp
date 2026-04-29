#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF=0x3f3f3f3f;
const int INFLL=0x3f3f3f3f3f3f3f3f;
int f(int x){
    int l=x>>4;
    //int r=x&((0<<8)*(0<<7)*(0<<6) *(0<<5) * l);
    int r=x^(l<<4);
    return (r<<4)|l;
}
void solve(){
    int ans=0;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        ans+=f(x);
    }
    cout << ans << endl;
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