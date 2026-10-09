#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n,m;
    cin >> n >> m;
    if(n==0||m>9*n){
        cout<<"-1 -1"<<endl;
        return;
    }
    if(m==0){
        if(n==1) cout<<"0 0"<<endl;
        else cout<<"-1 -1"<<endl;
        return;
    }
    vector<ll> mi(n+1,0), ma(n+1,0);
    ll tmp=m-1;
    mi[1]=1;
    for(ll i=n;i>=1&&tmp;--i){
        if(tmp>=9){
            mi[i]+=9;
            tmp-=9;
        }else{
            mi[i]+=tmp;
            break;
        }
    }
    for(ll i=1;i<=n;i++) cout<<mi[i];
    cout<<" ";
    tmp=m;
    for(ll i=1;i<=n&&tmp;i++){
        if(tmp>=9){
            ma[i]=9;
            tmp-=9;
        }else{
            ma[i]=tmp;
            break;
        }
    }
    for(ll i=1;i<=n;i++) cout<<ma[i];
    cout<<endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while(_--) {
        solve();
    }
    return 0;
}