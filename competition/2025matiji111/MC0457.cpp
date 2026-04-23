#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD=998244353;
int a[500005];
int b[500005];
void solve(){
    int n,q;
    cin >> n >> q;
    
    // int que[q+1];
    int temp=0;
    for(int i=1;i<=n;i++){
        cin >> temp;
        a[i]=(a[i-1]+temp)%MOD;
        b[i]=b[i-1]+((i%MOD)*(temp%MOD))%MOD;
    }
    int l,r;
    for(int i=1;i<=q;i++){
        cin >> l >> r;
        int p1=((l-1)%MOD)*((a[r]-a[l-1]+MOD)%MOD)%MOD;
        int p2=(b[r]-b[l-1]+MOD)%MOD;
        cout << (p2-p1+MOD)%MOD << endl;
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