#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
ll mex(ll x,ll y,ll z){
    
    ll ans=LONG_MAX;
    for(ll i=0;i<=3;i++){
        if(x!=i&& y!=i && z!=i){
            ans=i;
            return ans;
        }
    }
    return ans;
}
void solve() {
    ll n,k;
    cin >> n >> k;
    vector<ll > a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    vector<ll> b(n,0);
    while(k--){
        for(ll i=0;i<n;i++){
            b[i]=mex(a[i],a[(i+1)%n],a[(i+n-1)%n]);
        }
        a=b;
        for(auto x:a){
            cout << x << " ";
        }
        cout <<endl;
    }
    
    // if(k>=3){
    //     for(ll j=0;j<2;j++){
    //         vector<ll> tem(n,0);
    //         for(ll i=0;i<n;i++){
    //             if(j==0){
    //                 tem[i]=mex(a[i],a[(i+1)%n],a[(i+n-1)%n]);//ai, a(i+1) mod n, a(i+n−1) mod n
                    
    //             }else {
    //                 tem[i]=mex(b[i],b[(i+1)%n],b[(i+n-1)%n]);
                    
    //             }
                
    //         }
    //         if(j==0){
    //             b=tem;
    //         }else {
    //             c=tem;
    //         }
    //         //cout << "k:" <<k <<endl;
    //     }   
    //     if(k%2==0){
    //         for(auto x:c){
    //             cout << x << " ";
    //         }
    //         cout <<endl;
    //         return;
    //     }else {
    //         for(auto x:b){
    //             cout << x<<" ";
    //         }
    //         cout <<endl;
    //         return;
    //     }
    // }else {
    //     while(k--){
    //         vector<ll> tem(n);
    //         for(ll i=0;i<n;i++){
    //             tem[i]=mex(a[i],a[(i+1)%n],a[(i+n-1)%n]);//ai, a(i+1) mod n, a(i+n−1) mod n
    //         }
    //         a=tem;
    //     }
    //     for(auto x:a)cout << x << " " ;
    //     cout <<endl;
    // }
    
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