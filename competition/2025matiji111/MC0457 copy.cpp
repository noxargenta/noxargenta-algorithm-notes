#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD=998244353;
void solve(){
    int n,q;
    cin >> n >> q;
    int a[n+1];
    int b[n+1];
    a[0]=0;
    b[0]=0;
    // int que[q+1];
    for(int i=1;i<=n;i++){
        cin >> a[i];
        b[i]=(((i%MOD)*(a[i]%MOD))+(b[i-1]%MOD))%MOD;
        a[i]=(a[i]+a[i-1])%MOD;
    }
    int l,r;
    for(int i=1;i<=q;i++){
        cin >> l >> r;
        int part1 = (b[r] - b[l-1] + MOD) % MOD;
        int part2 = (a[r] - a[l-1] + MOD) % MOD;
        int offset = ((l - 1) % MOD * part2) % MOD;
        
        cout << (part1 - offset + MOD) % MOD << endl; 
    }

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