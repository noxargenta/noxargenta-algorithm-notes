#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll ji=0,ou=0;
    
    for(ll i=0;i<n;i++){
        cin >> a[i];
        if(a[i]%2==0){
            ou++;
        }else {
            ji++;
        }
    }
    if(n%2==1){
        cout << "NO\n";
        return; 
    }
    if(ji % 2==0 && ou%2==0){
        cout << "YES\n";
        return;
    }
    sort(a.begin(),a.end());
    ll sum=0;
    for(ll i=1;i<n;i++){
        if(a[i]==a[i-1]+1){
            sum++;
        }
    }
    if(sum){
        cout << "YES\n";
        return;
    }else {
        cout << "NO \n"  ;
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