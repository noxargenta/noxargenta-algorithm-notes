#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >>n;
    vector<ll> a(2*n+1);
    vector<ll> pre(2*n,0);
    vector<ll> b(2*n+1);
    for(ll i=1;i<=n;i++){
        cin >>a[i];
        a[i+n]=a[i];
        pre[i]=pre[i-1]+a[i];
    }
    for(ll i=n+1;i<=2*n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    // for(auto x:a){
    //     cout << x << " "; 
    // }
    deque<ll> d;
    for(ll i=1;i<=2*n;i++){
        if(d.empty()){
            d.push_back(i);
        }else{
            while(!d.empty() && d.front() <= i-n){
                d.pop_front();
            }
            while(!d.empty() && pre[d.back()]>pre[i]){
                d.pop_back();
            }
            d.push_back(i);
            if(i>n){
                b[i-n]=d.front();
            }
        }
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        if(pre[b[i]]-pre[i]>=0){
            ans++;
        }
    }
    cout <<ans <<endl;
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